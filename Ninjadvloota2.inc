| Based on original looting code of toomanynames

| The following updates were all individually posted and consolidated by Maskoi into the current version.

| Updated: Moeymoejoe added strip out comma in item names when accessing ini file 08/02/2006

| Updated: mystikule added sell option to ini file 01/07/2008

| Updated: drkrain for House of Thule 10/23/2010

| Updated: Maskoi with Sell Routines 11/27/2010

| Updated: Maskoi with item /ini commands o7/21/2011

| Updated: Maskoi with Foraged item handling 08/31/2011

| Selling Contributions by

| drkrain - TLInv item check

| dewey2461 - Add sold items to ini file Event

|

| Requirements: MQ2Moveutils

| Usage: add the following to your macro for looting

| #include Ninjadvloot.inc

| /call SetupAdvLootVars

| /call LootMobs

|

| Commands

| Usage. Grab the item and put it on your cursor then use one of the following commands

| /lootdestroy - Mark item on cursor to Destroy in loot.ini file

| /lootignore - Mark item on cursor to Ignore in loot.ini file

| /lootkeep - Mark item on cursor to Keep in loot.ini file

| /lootsell - Mark item on cursor to Sell in loot.ini file

| /sellstuff - Target a vendor and this command will sell any item in your inventory marked sell. Does not work with Veteran AA Resupply Agent.

| /depositstuff - Target your guildbanker and this command will deposit any item in your inventory marked keep into the guild bank.

#define RetryCorpse 5

#Event ALCantLoot "#*#may not loot this corpse#*#"

#Event ALCantLoot "Someone is already looting that corpse."

#Event ALCantLoot "#*#You are too far away to loot that corpse#*#"

#Event ALCantLoot "#*#Corpse too far away.#*#"

#Event Sell "#*#You receive#*# for the #1#(s)#*#"

#Event EditIniItem "[MQ2] LootIniItem #1# #2#"

#Event SellStuff "[MQ2] NinjadvLoot selling items to vendor"

#Event Broke "#*#you cannot afford#*#" 

#Event Broke "#*#you can't afford#*#" 

#Event Forage "Your forage mastery has enabled you to find something else!"

#Event Forage "You have scrounged up #*#"

#Event Reset "Error: Corpse::LootItem: BeingLootedBy != client"

Sub SetupAdvLootVars




 /declare ALDontLoot int outer 

 /declare CorpseRotTimer timer outer

 /declare NinjadVersion string outer 2.3

 /declare NinjaIniFile string outer Loot.ini

/declare CorpseTries int outer 

 /call ALLoadVar Settings Version "${NinjadVersion}" string

 /call ALLoadVar Settings LootMobs TRUE bool

 /call ALLoadVar Settings CorpseRadius 2000 int

 /call ALLoadVar Settings MobsTooClose 10 int

 /call ALLoadVar Settings CorpseRotTime 440s string

 /call ALLoadVar Settings ReportLoot FALSE bool

 /call ALLoadVar Settings LootChannel g string

 /call ALLoadVar Settings LootSpam 1 int

 | Sell loot settings

 /call ALLoadVar Settings OpenAllBags 1 int

 /call ALLoadVar Settings AddNewSales 1 int

 /call ALLoadVar Settings LootForage 1 int

 

 /if (!${Defined[${AlertList}]}) /declare AlertList int outer 9

 /squelch /alert clear 25
/echo NinjadVersion:${NinjadVersion} Version:${Version}
 /if (${Version.Equal[${NinjadVersion}]}) {

 /echo NinjAdvLoot version mismatch detected writing aliases.

 /noparse /squelch /alias /lootignore /echo LootIniItem Ignore ${Cursor.Name}

 /noparse /squelch /alias /lootsell /echo LootIniItem Sell ${Cursor.Name}

 /noparse /squelch /alias /lootkeep /echo LootIniItem Keep ${Cursor.Name}

 /noparse /squelch /alias /lootdestroy /echo LootIniItem Destroy ${Cursor.Name}

 /squelch /alias /sellstuff /echo NinjadvLoot selling items to vendor

 /squelch /alias /depositstuff /echo NinjadvLoot depositing items to guildbank

 /ini "Loot.ini" "Settings" "Version" "${NinjadVersion}"

 }

/return



Sub ALLoadVar(IniSection,IniVar,IniValue,VarType)



 /if (!${Defined[${IniVar}]} && ${Defined[VarType]}) /declare ${IniVar} ${VarType} outer

 /declare IniString string local ${Ini[Loot.ini,${IniSection},${IniVar},NOTFOUND]}

 /varset ${IniVar} ${IniString}

 /if (${IniString.Equal["NOTFOUND"]}) {

 /if (${IniString.Equal["NOTFOUND"]}) /varset ${IniVar} ${IniValue}

 /ini "Loot.ini" "${IniSection}" "${IniVar}" "${${IniVar}}"

 } 



/return



| **************** Loot Mobs Section ******************** |

Sub Event_ALCantLoot(Line)
|/squelch /alert add 25 id ${ALDontLoot}
/varset CorpseTries ${Math.Calc[${CorpseTries}+1]}
/return 

Sub Event_EEALCantLoot(Line)

/if (${Line.Find[may not loot this corpse]}) {
	/varset CorpseTries ${Math.Calc[${CorpseTries}+1]}
	/echo Corpsetry ${CorpseTries}
	/if (${CorpseTries}>5) {
		
		 /varset ALDontLoot ${Target.ID}
		 
	}
} else {
 	/varset ALDontLoot ${Target.ID}
 	/squelch /alert add 25 id ${ALDontLoot}
 }

 
/return

Sub Event_Reset
	/echo Restarting Loot...
 /call LootMobs
/return

Sub LootMobs

 /squelch /alert add ${AlertList} untargetable
 
 |/squelch /alert add ${AlertList} nopcnear 10

 /squelch /alert add ${AlertList} campfire

 /squelch /alert add ${AlertList} npc "steadfast servant"

 /squelch /alert add ${AlertList} npc "a jester of bristlebane"



 /if (!${CorpseRotTimer}) {

 /squelch /alert clear 25

 }

/if (${DoLoot}==1) {
 	/declare DeadCount int local ${SpawnCount[corpse radius ${CorpseRadius} noalert 25 range 1# 300# ]}
 } 
 
 /if (${DoLoot}==2) {

	|/declare DeadCount int local ${SpawnCount[corpse radius ${CorpseRadius} # noalert 25 range 1# 300# ]}
	/declare ncount int local 0
	/for lx 1 to 10
		/if ( ${namedMobsToLoot[${lx}]} > 0 ) /varset ncount ${Math.Calc[${ncount}+1]}
	/next lx

	/declare DeadCount int local ${ncount}
	/echo Looting ${ncount} Named mobs!
 }
 /call CheckXTargetAggro
 /if (!${LootMobs} || ${Macro.Return}>0 || ${SpawnCount[npc radius ${MobsTooClose} range 1# 300# noalert ${AlertList} ]} || !${DeadCount} || ${Me.Combat} || (${Cursor.NoDrop} && !${Me.FreeInventory})) {

 /echo Lootfail

 /if (${SpawnCount[npc radius ${MobsTooClose} noalert ${AlertList} range 1# 300# ]}) /echo mobs too close.

 /if (!${DeadCount}) /echo no corpse nearby.

 /return

 }



 /declare i int local

 /declare CorpseList string local |

 /declare CorpseToLoot int local


/if (${DoLoot}==1) {
 /for i 1 to ${DeadCount}


 /varset CorpseList ${CorpseList}${NearestSpawn[${i},corpse radius ${CorpseRadius} noalert 25 range 1# 300# ].ID}|
 /next i
} 


 

 /if (${DoLoot}==2) {
	 /for lx 1 to 10 
	 	/if (${namedMobsToLoot[${lx}]}>0) {
			 /varset CorpseList ${CorpseList}${namedMobsToLoot[${lx}]}|
		 }
	 /next lx
 }
 
 

 /for i 1 to ${DeadCount}

 /if (${Me.FreeInventory}<3) {

 /echo inventory full

 /goto :Done

 }


/call CheckXTargetAggro
 /if (${SpawnCount[npc radius ${MaxRad2} zradius ${MaxZ2} targetable noalert 1 range ${TargMin} ${TargMax} ]} || ${Macro.Return}>0) {

 /echo Agro!

 /goto :Done	

 }





 /varset CorpseToLoot ${Spawn[${CorpseList.Arg[${i},|]}].ID} 


:reLootDroga
 /if (${Spawn[${CorpseToLoot}].Deity.ID} || !${Spawn[${CorpseToLoot}].ID}) /goto :SkipCorpse

 /if (${Target.ID}!=${CorpseToLoot}) /target id ${CorpseToLoot} range 1 400

 /if (!${Me.Standing}) /stand

 /delay 2s ${Target.ID}==${CorpseToLoot} && ${Me.Standing}



 /if (${Target.Distance}>10 || ${Target.DistanceZ}>30) {

 /warp t

 /delay 1

 }

 /if (${Target.DistanceZ}>30) {

 /echo Z

 /tar clear

 /goto :SkipCorpse 

 }

 /if (${Target.Distance}<11) /call LootCorpse
 /delay 1
 /doevents
 
 /if (${Spawn[id ${CorpseToLoot}].ID} && ${ALDontLoot}!=${CorpseToLoot}) /goto :reLootDroga

 }

 /delay 1s

 :SkipCorpse

 /next i

:Done


/return



Sub LootCorpse

 /declare i int local

 /declare loo int local
 /varset CorpseTries 0
 
 
 /declare LootList string local
 /declare LastLootSeen int local 
 /declare LootItemFor int local
 /declare FirstLetter string local
 /declare LoopOverItems int local
 /declare corpsID int

 /call CheckCursor

 

|	/loot
/if (${Target.ID} == 0) /return

/echo Looting ${Target.Name} id:${Target.ID}

 /if (${Window[LargeDialogWindow].Open} && !${BeepTimer}) {

 /call AntiBot

 }



 :WaitForLootWndOpen

 /for loo 1 to 10

 /loot

 /delay 2 !${Window[LootWnd].Open}

 /delay 4 ${Window[LootWnd].Open}
 /doevents ALCantLoot
 
 /if (${CorpseTries}>5) {
 	/squelch /alert add 25 id ${ALDontLoot}
	 /echo Failed to loot 5 times ignoring...
	/return
 }
 /if (${Target.ID}==${ALDontLoot} && ${Spawn[${ALDontLoot}].ID}) {

	/squelch /alert add 25 id ${ALDontLoot}
	/return
 }
 /if (!${Window[LootWnd].Open} && ${Target.Type.Equal[Corpse]}) /next loo

  /if (${Target.ID}==${ALDontLoot} && ${Spawn[${ALDontLoot}].ID}) {

	
	/return
 }

 

 /delay 3

/if (${Corpse.Open} && ${Corpse.Items}) {

 /declare loottotal int local 
 /varset LoopOverItems 3
 /varset LastLootSeen ${Corpse.Items}
 /declare lagcount int local 
 
 
 
 :newLootLoop
 
 /for i 1 to 30


/if (${Corpse.Item[${i}].ID}) {
	/if (${LastLootSeen} < ${i} ) {
		/echo Adding LoopOver
		/varcalc LoopOverItems ${LoopOverItems}+1
		/varset LastLootSeen ${i}
		/delay 1
	}
	 /varset FirstLetter ${Corpse.Item[${i}].Name.Left[1]}



	 /if (${Corpse.Item[${i}].ID} && !${Select[${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"]},Ignore,Keep,Destroy,Sell]}) {

	 /if (${Corpse.Item[${i}].NoDrop}) /ini "${NinjaIniFile}" "${FirstLetter}" "${Corpse.Item[${i}]}" Keep

	 /if (!${Corpse.Item[${i}].NoDrop}) /ini "${NinjaIniFile}" "${FirstLetter}" "${Corpse.Item[${i}]}" Keep

	 } 



	  /if (${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"].NotEqual[Destroy]} && !${Me.FreeInventory} && (!${FindItemCount[=${Corpse.Item[${i}].Name}]} || (${FindItemCount[=${Corpse.Item[${i}].Name}]} && ${Corpse.Item[${i}].Stackable} && !${Corpse.Item[${i}].FreeStack})) || ${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"].Equal[Ignore]}) /varset LootList ${LootList}${Corpse.Item[${i}]},

	 /if ((${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"].Equal[Keep]} || ${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"].Equal[Sell]}) && (${Me.FreeInventory} || (${FindItemCount[=${Corpse.Item[${i}].Name}]} && ${Corpse.Item[${i}].Stackable} && ${Corpse.Item[${i}].FreeStack}))) {
		/echo Looting ${Corpse.Item[${i}].Name}
		/if ( !${Corpse.Item[${i}].Lore} ) {
			/call LootItem ${i} Keep Right
			|/delay 1
		} else  {
				/call CheckLoreItem ${Corpse.Item[${i}].ID}
				/if (${Macro.Return}==0) /call LootItem ${i} Keep Right
			|/delay 1
		}
	 }

	 /if (${Ini[${NinjaIniFile},"${FirstLetter}","${Corpse.Item[${i}]}"].Equal[Destroy]}) /call LootItem ${i} Destroy left

}

 



 /next i
 /varcalc LoopOverItems ${LoopOverItems}-1
 
 /if (${LoopOverItems}>=1) {
	|/echo LoopOver ${LoopOverItems}
	/delay 1
	/goto :newLootLoop
	
	}
|/echo LootDone!
/if (${DoLoot}==2 && ${Target.ID}) {
	
	 /for lx 1 to 10
	 	/if (${namedMobsToLoot[${lx}]}==${Target.ID}) {
			 /echo Removed ${Target.CleanName} from Named Loot list.
 			 /varset namedMobsToLoot[${lx}] 0
 }
 /if (${Target.ID}) {

 /squelch /alert add 25 id ${Target.ID}

 }

 /if (!${CorpseRotTimer}) /varset CorpseRotTimer ${CorpseRotTime}

 }

 }

 :clickdoneffs

 /nomodkey /notify LootWnd LW_DoneButton leftmouseup

 /delay 1s !${Corpse.Open}

 /if (${Corpse.Open}) /goto :clickdoneffs

 

/return



Sub LootItem(int i,DoWhat,WhichButton)
 /declare OldItemCount int local ${FindItemCount[=${Corpse.Item[${i}].Name}]}
 /declare ItemName string local ${Corpse.Item[${i}].Name}
 /declare RetryCount int local 0

 /declare CorpseItemID int local ${Corpse.Item[${i}].ID}
 
 


 /nomodkey /shift /itemnotify ${Corpse.Item[${i}].InvSlot} ${WhichButton}mouseup

 /delay 5s ${Window[ConfirmationDialogBox].Open} || !${Corpse.Item[${i}].NoDrop} || !${Window[LootWnd].Open}

 /if (${Window[ConfirmationDialogBox].Open}) /nomodkey /notify ConfirmationDialogBox Yes_Button leftmouseup

 /delay 5s ${Cursor.ID} || ${WhichButton.NotEqual[left]} || !${Window[LootWnd].Open}

 /if (${DoWhat.Equal[Destroy]} && ${Cursor.ID}==${CorpseItemID}) /destroy

 /delay 10s !${Corpse.Item[${i}].ID} && ${OldItemCount}<${FindItemCount[${ItemName}]} || !${Window[LootWnd].Open}

 /delay 1

 /if (${Cursor.ID}) /call CheckCursor

/return



Sub CheckCursor

 :ALauto_inv

 /if (${Cursor.ID}) {

 /if (${Cursor.ID}==150001) {
	/echo Epic 5 Collection bag!
	/bcaa //popup ${Me.CleanName} has a Epic 5 Collection bag on the cursor and no free inventory! Ending macro at safespot!
	/stick off
	/melee off
	/stick off
	/warp s
	/delay 1s
	/endm
 }
 /if (${Cursor.NoDrop} && !${Me.FreeInventory}) /return
 
 /declare ty int local
 /declare itemInMainslot int 0
 
 /for ty 1 to 8
	/if ( !${Me.Inventory[pack${ty}].Container} ) {
	
		/varset itemInMainslot ${ty}
	}
 /next ty
 /if ( ${Cursor.Container} && !${itemInMainslot} ) {
	
	/bcaa //popup ${Me.CleanName} has a ${Cursor.Name} on the cursor and no free inventory! Ending macro at safespot!
	/delay 1s
	/stick off
	/melee off
	/stick off
	/warp s
	/delay 1s 
	/endmacro
 }
 
 /if ( ${Cursor.Container} && ${itemInMainslot}) {
	/itemnotify pack${itemInMainslot} leftmouseup
	/delay 5
	/if (${Cursor.Container}) /goto :ALauto_inv
	
 }
 
/timed 5 /autoinventory

 /delay 2s !${Cursor.ID}
 /goto :ALauto_inv

 }

/return



| **************** Foraged Items Section ******************** |

Sub Event_Forage

 /if (!${LootForage}) /return

 /declare ForagedItem string local

 :MoreToAutoInventory

 /if (${Cursor.ID}) {

 /varset ForagedItem ${Cursor.Name}

 /if (!${Select[${Ini[Loot.ini,"${Cursor.Name.Left[1]}","${Cursor.Name}"]},Ignore,Keep,Destroy,Sell]}) {

 /if (${Cursor.ID}) /ini "loot.ini" "${Cursor.Name.Left[1]}" "${Cursor.Name}" Keep

 /if (${LootSpam}) /echo New foraged item >> ${Cursor.Name} << added to ini file. 

 }

 /if (${Ini[Loot.ini,"${Cursor.Name.Left[1]}","${Cursor.Name}"].Equal[Destroy]} || ${Ini[Loot.ini,"${Cursor.Name.Left[1]}","${Cursor.Name}"].Equal[Ignore]}) {

  /if (${Cursor.Name.Equal[${ForagedItem}]}) /destroy

 /delay 5

 /if (${LootSpam}) /echo NINJADVLOOT -- Destroyed foraged ${ForagedItem}.

 } else /if ((${Ini[Loot.ini,"${Cursor.Name.Left[1]}","${Cursor.Name}"].Equal[Keep]} || ${Ini[Loot.ini,"${Cursor.Name.Left[1]}","${Cursor.Name}"].Equal[Sell]}) && (!${Cursor.Lore} || !${FindItem[${Cursor.Name}].ID}) && (${Me.FreeInventory} || (${FindItemCount[=${Cursor.Name}]} && ${Cursor.Stackable} && ${Cursor.FreeStack}))) {

 /if (${LootSpam}) /echo NINJADVLOOT ++ Kept foraged ${ForagedItem}.

 /autoinventory

 /delay 5

 }

 }

 /if (${Cursor.ID}) /goto :MoreToAutoInventory

/return



| **************** Search Loot Section ******************** |

Sub DoLootStuff(LootAction)

 /declare i int local

 /declare j int local

 /declare k int local

 /declare LootItem string

 /if (${OpenAllBags}) {

 /echo Opening all bags

 /keypress OPEN_INV_BAGS

 }

 /call NPC "${Target.CleanName}"

 | Top level inv has its own loop since ${FindItem[=${ItemToSell}].InvSlot} looks at top lev inv slots first in Sub SellToVendor for the item to sell.

 | Loop through top level inventory slots for sellable items

 /for k 1 to 10

 | Check if top level inv slot is not a container/bag

 /if (${InvSlot[pack${k}].Item.Container}==0) {

 | If top level inv slot is empty check for an item marked sell

 /if (${InvSlot[pack${k}].Item.ID}) {

 /varset LootItem ${InvSlot[pack${k}].Item}

 /if (${LootAction.Equal[sell]}) {

 /if (${Ini[Loot.ini,"${LootItem.Left[1]}","${LootItem}"].Equal[Sell]}) /call SellToVendor "${LootItem}"

 }

 /if (${LootAction.Equal[deposit]}) {

 /if (${Ini[Loot.ini,"${LootItem.Left[1]}","${LootItem}"].Equal[Keep]}) /call DepositToGuildBank "${LootItem}"

 }

 }

 }

 /next k 

 | Loop through top level inventory slots for containers

 /for i 1 to 10

 | Check if top level inv slot has a bag

 /if (${InvSlot[pack${i}].Item.Container}==0) /next i

 | Set j 1 to number of bag slots and loop through slots looking for items marked sell

 /for j 1 to ${InvSlot[pack${i}].Item.Container}

 /if (${InvSlot[pack${i}].Item.Item[${j}].ID}) {

 

 /varset LootItem ${InvSlot[pack${i}].Item.Item[${j}].Name}

 /if (${LootAction.Equal[sell]}) {

 /if (${Ini[Loot.ini,"${LootItem.Left[1]}","${LootItem}"].Equal[Sell]}) /call SellToVendor "${LootItem}"

 }

 /if (${LootAction.Equal[deposit]}) {

 /if (${Ini[Loot.ini,"${LootItem.Left[1]}","${LootItem}"].Equal[Keep]}) /call DepositToGuildBank "${LootItem}"

 }

 }

 /next j

 /next i



 /if (${OpenAllBags}) {

 /echo Closing all bags

 /keypress CLOSE_INV_BAGS

 }

 | Prevent spam from Sell event after selling items in Sub SellStuff

 /doevents flush Sell

 /if (${Window[MerchantWnd].Open}) {

 /echo Closing merchant window

 /nomodkey /notify MerchantWnd MW_Done_Button LeftMouseUp

 }

 /if (${Window[GuildBankWnd].Open}) {

 /echo Closing guildbank window

 /keypress esc

 }

/return

 

Sub NPC(NPCName)

 /target npc ${NPCName} range 1 400

 /delay 1s

 /if (!${Select[${Target.Type},npc,pet]} || !${Target.ID} || ${Target.Type.Equal[pet]} && !${Target.CleanName.Find[familiar]}) {

 /echo Please target a vendor or guildbanker

 /return

 }

 /echo Doing business with ${NPCName}

 /target id ${Spawn[${NPCName} range 1 400].ID} range 1 400

 /if (${Target.Distance}>15) /stick front 10

 /delay 1s

 /stick off

 /face nolook

 /delay 1s

 /echo Opening merchant/guildbank window

 /nomodkey /click right target

 /echo Waiting 5s for merchant/guildbank window to populate

 /delay 5s

/return



| **************** Sell Loot Section ******************** |

Sub Event_Sell(string soldstr, string ItemName)

 /if ( ${AddNewSales} ) {

 /echo Setting ${ItemName} to sell

 /ini "loot.ini" "${ItemName.Left[1]}" "${ItemName}" Sell

 }

/return



Sub SellToVendor(ItemToSell)

 /if (${Window[MerchantWnd].Open}) {

 :sell

 /echo Selling ${ItemToSell}

 /nomodkey /itemnotify ${FindItem[=${ItemToSell}].InvSlot} leftmouseup

 /delay 15s ${SelectedItem.ID}

 /nomodkey /shiftkey /notify merchantwnd MW_Sell_Button leftmouseup

 /delay 15s !${SelectedItem.ID}



 /if (${FindItem[${itemToSell}].InvSlot}) /goto :sell

 }

/return



| **************** Deposit Loot Section ******************** 

Sub DepositToGuildBank(ItemToDeposit)

 /if (${Window[GuildBankWnd].Open}) {

 :deposit

 /if (${Window[GuildBankWnd].Child[GBANK_DepositCountLabel].Text.Arg[2,:]}==0) {

 /echo Guildbank Deposited Items is full.

 /return

 }

 /echo Depositing ${ItemToDeposit}

 /nomodkey /shiftkey /itemnotify ${FindItem[=${ItemToDeposit}].InvSlot} leftmouseup

 /delay 5

 /nomodkey /notify GuildBankWnd GBANK_DepositButton leftmouseup

 /delay 2s

 /if (${FindItem[${itemToSell}].InvSlot}) /goto :deposit

 }

/return



| **************** Item set ini file event ******************** 

 Sub Event_EditIniItem(ItemString,ItemAction,ItemName)

 /if (${Cursor.ID}) {

 /echo -- Setting ${ItemName} to ${ItemAction}

 /ini "loot.ini" ${ItemName.Left[1]} "${ItemName}" ${ItemAction}

 } else {

 /echo No item on cursor.

 }

 /return



| **************** Sell Stuff Event ******************** 

 Sub Event_SellStuff

 /call DoLootStuff sell

 /return

 

| **************** Deposit Stuff Event *******************

 Sub Event_DepositStuff

 /call DoLootStuff deposit

 /return

 

| **************** Broke Event ******************** 

Sub Event_Broke 

 /echo You are out of money! 

 /endmacro 

/return



| **************** Type Stuff ******************** 

| Lifted from commonsubs.inc by Armysoldier 

 Sub Type(InStr) 

 /declare char string local 

 /declare loopctr int local 

 /for loopctr 1 to ${InStr.Length} 

 /varset char ${InStr.Mid[${loopctr},1]} 

 /if (!${char.Length}) { 

 /nomodkey /keypress space chat 

 } else { 

 /nomodkey /keypress ${char} chat 

 } 

 /next loopctr 

/return 



| **************** Buy Stuff ******************** 

Sub Buy(string ItemToBuy, int amount)

 /declare i int local

 /echo Buying ${ItemToBuy}!

 /declare QTY int local

 /declare ListItem int local

 /varset QTY ${Math.Calc[${amount}-${FindItemCount[${ItemToBuy}]}]}

 /delay 1s

 /if (${FindItemCount[${ItemToBuy}]}>= ${amount}) {

 /echo Done!

 /return

 } 

 /varset ListItem ${Window[MerchantWnd].Child[ItemList].List[=${ItemToBuy},2]}

 /if (!${ListItem}) {

 /echo couldn't find ${ItemToBuy}

 /return

 } else {

 /notify MerchantWnd ItemList listselect ${ListItem}

 /delay 1s 

 } 

 /echo Buying ${ItemToBuy} Till I get ${amount} 

 :Loop

 /if (${QTY}>1) {

 /if (${QTY}>19) {

 /Shiftkey /notify merchantwnd MW_Buy_Button leftmouseup

 /delay 5s ${FindItemCount[${ItemToBuy}]}>=${amount}

 /echo ${FindItemCount[${ItemToBuy}]} ${ItemToBuy} in inventory

 /varset QTY ${Math.Calc[${amount}-${FindItemCount[${ItemToBuy}]}]} 

 /delay 3

 /if (${QTY}<=0) /return

 /goto :Loop

 }

 /if (${QTY}>0 && ${QTY}<20) {

 /for i 1 to ${QTY}

 /notify merchantwnd MW_Buy_Button leftmouseup

 /echo Buying ${ItemToBuy} ${i} of ${QTY}

 /varcalc QTY ${amount}-${FindItemCount[${ItemToBuy}]}

 /echo ${QTY}

 /if (${QTY}<=0) /return

 /next i

 }

 }

 /return
 
 Sub CheckXTargetAggro

	/declare Sum int local
	/declare x int local
	
	/for x 1 to 13
		/if ( ${Me.XTarget[${x}].ID} > 0 && !${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[Untargetable]} && ${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[NPC]}) /varcalc Sum ${Sum}+1
	/next x

/return ${Sum}
