#Event Invite "#*# tells you, 'group'"

#Event Invited "#*# invites you to join a group."

#event Ubaid "#*#This makes 0 Deaths#*#"

#event DrogaZI "Caridwi whispers, #*#"

Sub CreateIni
/ini a2.ini a2 Version 1
/call WriteAlert "steadfast servant"
/call WriteAlert "race teleport man"
/call WriteAlert "race invisible man"
/call WriteAlert "furious sentry"
/call WriteAlert "Tatsujiro the Serene"
/call WriteAlert "chaotic jester"
/call WriteAlert "The Butler"
/call WriteAlert "Lord Brekt"
/call WriteAlert "Norrath`s Keepers Guard"
/call WriteAlert "Vulak"
/call WriteAlert "Kerchak"
/call WriteAlert "guardian spirit"
/call WriteAlert "Caridwi"
/call WriteAlert "festering ooze"
/call WriteAlert "dusty barrel"
/call WriteAlert "Jaques the Infected"
/call WriteAlert "time bender"
/call WriteAlert "pioneer vulu"
/call WriteAlert "Jaelle Florica"
/call WriteAlert "Scout Madu"
/call WriteAlert "Blacktalon"
/call WriteAlert "Fabled Antibotter"
/call WriteAlert "jester of bristlebane"
/call WriteAlert "killer wasp"
/call WriteAlert "essence of fire"
/call WriteAlert "a menacing tree spirit"
/call WriteAlert "Jagged Blades"
/call WriteAlert "Durgin Skell"
/call WriteAlert "Trakanon"
/call WriteAlert "a hatchling"
/call WriteAlert "The Quiet Wanderer"
/call WriteAlert "Moldmaster Gangii"
/call WriteAlert "a hill giant"
/call WriteAlert "Caridwa"
/call WriteAlert "Warm Light"
/call WriteAlert "Scount Madu"
/call WriteAlert "Pioneer Vulu"
/call WriteAlert "Jaelle Florica"
/call WriteAlert "Guardian Krogone"
/call WriteAlert "The Mechamatic Guardian"
/call WriteAlert "The Golden Maiden"
/call WriteAlert "005"
/call WriteAlert "Emissary Tinnvin"
/ini a2.ini Ldons Bosses /first/second/third/fourth/fifth/sixth/seventh/eighth/ninth/tenth/eleventh/twelfth/thirteenth/fourteenth/fifteenth/
/return

Sub WriteAlert(inString)
	/declare x1 int local
	/for x1 1 to 100
		/if (${Ini[a2.ini,GlobalAvoid,Avoid${x1}].Length}==0) {
			/ini a2.ini GlobalAvoid Avoid${x1} "${inString}"
			/return
		}
	/next x1
/return

Sub AddAlerts

/alert clear 1

/alert clear 2
/alert clear 3
/alert clear 4
/alert clear 5

/alert add 1 ${Me.Name}
/alert clear 60
/delay 2

/for lx 1 to 1000
	/if (${Ini[a2.ini,GlobalAvoid,Avoid${lx}].Length}>0) {
		/alert add 1 "${Ini[a2.ini,GlobalAvoid,Avoid${lx}]}"
	} else {
		/varset lx 1000
	}
/next lx

/for lx 1 to 1000
	/if (${Ini[a2.ini,${Zone.ShortName},Avoid${lx}].Length}>0) {
		/alert add 1 "${Ini[a2.ini,${Zone.ShortName},Avoid${lx}]}"
	} else {
		/varset lx 1000
	}
/next lx

/alert add 2 pc ${Me.CleanName}

|/alert add 1 npc "a petrified colossal tree"
|/alert add 1 npc "a hollow tree"

/alert add 3 npc "pirate runners skiff"


/alert add 60 npc "Vishimtar"


/alert add 4 npc "steadfast servant"


/alert add 5 pc ${Me.Name}







/echo Alerts updated.

/delay 5



/return





sub AntiBot

/return

 /delay ${Math.Calc[2+${Math.Rand[5]}]}s



/declare anti int



/declare textcount int 12



/declare Anti1 string local There are horses in the Bazaar

/declare Anti2 string local Wood Elves are smaller than Barbarians

/declare Anti3 string local Ogres are taller than Dwarves

/declare Anti4 string local Gnomes are short

/declare Anti5 string local Wood Elves are smaller than Barbarians

/declare Anti6 string local Dwarves are good at growing beards

/declare Anti7 string local Hill Giants are tall

/declare Anti8 string local Dragons have scales

/declare Anti9 string local Berzerkers cast less spells than wizards

/declare Anti10 string local Anyone can get a Godly pet

/declare Anti11 string local Skeletons are undead

/declare Anti12 string local Humans can grow hair



 

 

 /for anti 1 to ${textcount}

 /if (${Window[LargeDialogWindow].Child[LDW_TextBox].Text.Find[${Anti${anti}}]}) {

 /notify LargeDialogWindow LDW_YesButton leftmouseup

 /echo Yes, ${Anti${anti}}

 /gu ${Time}

 /return

 }

 /next anti

 

 

 /notify LargeDialogWindow LDW_NoButton leftmouseup

 /gu ${Time}

 

 

/return





Sub BuffCheck



:check

/if (${Me.Pet.ID} && ${PetHealPct} && ${Me.Pet.PctHPs}<=${PetHealPct} && ${Me.AltAbilityReady[${PetHeal}]}) {
	/target id ${Pet.ID}
	/delay 3
	/echo Healing pet with ${PetHeal} 
	/call cast "${PetHeal}" alt
}


/if (!${Me.Buff["Horror of Darkness"].ID} && ${FindItemCount[=Legendary Rebirth Charm]}) {

 /delay 1s

 /itemnotify charm rightmouseup

 /delay 1s

 }



/if ( ${Me.Level} >= 85 && ${Me.Buff["Bottle of Adventure III"].Duration.TotalSeconds}<120 && ${FindItemCount[=Bottle of Adventure III]} && !${Me.Buff[Lesson of the Devoted].ID} && !${Me.Buff[Heightened Learning].ID}) {

 /delay 1s

 |/Potionbelt activate 3
|/itemnotify ${FindItem[=Bottle of Adventure III].InvSlot} rightmouseup
/call ClickItem "Bottle of Adventure III"
 /delay 10s ${Me.Buff["Bottle of Adventure III"].Duration.TotalSeconds}>120

 /delay 1s

 }





/if (${Me.Level} >= 85 && ${Me.Buff["Elixir of Speed X"].Duration.TotalSeconds}<120 && ${Spell["Elixir of Speed X"].Stacks} && ${FindItemCount[=Distillate of Alacrity X]}) {	

 /delay 1s

 |/Potionbelt activate 4
|/itemnotify ${FindItem[=Distillate of Alacrity X].InvSlot} rightmouseup
/call ClickItem "Distillate of Alacrity X"
 /delay 5s ${Me.Buff["Elixir of Speed X"].Duration.TotalSeconds}>120

 /delay 1s

 }

 

/if (${Me.Buff["Frostreaver's Blessing"].Duration.TotalSeconds}<300 && ${Spell["Frostreaver's Blessing"].Stacks} && ${FindItemCount[=Ring of Dain Frostreaver IV]}) {	

 /delay 5

 |/casting "Ring of Dain Frostreaver IV" -item
|/itemnotify ${FindItem[=Ring of Dain Frostreaver IV].InvSlot} rightmouseup
/call ClickItem "Ring of Dain Frostreaver IV"
 /delay 2s

 }



/if (${Me.Buff["Illusionary Spikes VII"].Duration.TotalSeconds}<300 && ${Spell["Illusionary Spikes VII"].Stacks} && ${FindItemCount[=Stormeye Band]}) {	

 /delay 5

 |/itemnotify rightfinger rightmouseup
 |/itemnotify ${FindItem[=Stormeye Band].InvSlot} rightmouseup
 /call ClickItem "Stormeye Band"
 /delay 2s

 }



/if (${FindItemCount[=Bloody Mantle of Agony]} && ${Me.Buff["Sacred Striking Courage of Brell"].Duration.TotalSeconds}<300 && ${Spell["Sacred Striking Courage of Brell"].Stacks}) {	

 |/itemnotify shoulder rightmouseup
|/itemnotify ${FindItem[=Bloody Mantle of Agony].InvSlot} rightmouseup
/call ClickItem "Bloody Mantle of Agony"
 /delay 1s

 }

 /if (${FindItemCount[=Ring of the Dreamslayer]} && ${Me.Buff["Ancestral Memories III"].Duration.TotalSeconds}<300 && ${Spell["Ancestral Memories III"].Stacks}) {	

 |/itemnotify shoulder rightmouseup
|/itemnotify ${FindItem[=Ring of the Dreamslayer].InvSlot} rightmouseup
/call ClickItem "Ring of the Dreamslayer"
 /delay 1s

 }

/if (${FindItemCount[=Earring of Reverie]} && ${Me.Buff["Might of Stone VI"].Duration.TotalSeconds}<300 && ${Spell["Might of Stone VI"].Stacks}) {	

 |/itemnotify shoulder rightmouseup
|/itemnotify ${FindItem[=Earring of Reverie].InvSlot} 
/call ClickItem "Earring of Reverie"
 /delay 1s

 }

/if ((${Me.Buff[Insidious Malady].ID} || ${Me.Buff[Howl of Tashan].ID} || ${Me.Buff[Plague of Hulcror].ID}) && ${FindItemCount[=Ring of Slaughtering Cures]} && ${Cast.Ready[Ring of Slaughtering Cures]}) {

 /delay 5

 |/casting "Ring of Slaughtering Cures" -item
|/itemnotify ${FindItem[=Ring of Slaughtering Cures].InvSlot} rightmouseup
/call ClickItem "Ring of Slaughtering Cures"
 /delay 3s

 }



/if (${Me.Song[Circle of Power III].Duration.TotalSeconds}<10 && ${FindItemCount[=Golden Dragonlinked Chestguard]} && ${DoCritBuff}) {

 /delay 5

 |/casting "Golden Dragonlinked Chestguard" - item	
|/itemnotify ${FindItem[=Golden Dragonlinked Chestguard].InvSlot} rightmouseup
/call ClickItem "Golden Dragonlinked Chestguard"
 /varset ChestTimer 1s

 /delay 3s ${Me.Song[Circle of Power III].ID}

 /delay 5

 }



 

/return



Sub Event_Invite





 /delay 15



 /if (${String[${Group.Leader}].Equal[${Me}]} || !${Group.Members}) {



 /invite ${MacroQuest.LastTell}



 /delay 5s



 /g please drop group when you leave



 } else {



 /tell ${MacroQuest.LastTell} I'm not the leader ${Group.Leader} is, send them a tell for an invite



 }







/return



Sub Event_Invited



/if (${Group.Members}) {

 /tell ${MacroQuest.LastTell} Already in a group ask the leader ${Group.Leader} for invite.

 }

/if (!${Group.Members}) {

 /notify GroupWindow GW_FollowButton leftmouseup

 /delay 2s

 /g Thanks, AFK.

 }



 



/return





Sub Event_Ubaid

/echo Ubaid Spawned



/beep
/beep 
/beep
/return



Sub ZoneToV



:ToV

/if (${Zone.ID}!=124) {

 /say #peqzone 124

 /delay 30s ${Zone.ID}==124

 /goto :tov

 }

/delay 5s



:Caridwi

/squelch tar clear

/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say templeveeshan instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/hidec all

/hidec looted





/return





Sub ZoneKael



/if (${Zone.ID}==492) /goto :Caridwi



:Brells

/if (${Zone.ID}!=492) {

 /say #peqzone 492

 /delay 30s ${Zone.ID}==492

 /goto :Brells

 }





/delay 5s



:Caridwi



/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say kael instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>5



 /if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/delay 5s



/hidec all

/hidec looted



/return







Sub ZoneVexThal

/if (${Zone.ID}==158) /goto :done

:VT



/if (${Zone.ID}!=158) {

 /say #peqzone 158

 /delay 30s ${Zone.ID}==158

 /goto :VT

 }

/delay 5s



:Caridwi

/squelch tar clear

/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say vexthal instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



:done

/hidec all

/hidec looted





/return





Sub ZoneKarnor



:Karnor

/if (${Zone.ID}!=102) {

 /say #peqzone 102

 /delay 30s ${Zone.ID}==102

 /goto :Karnor

 }

/delay 5s



:Caridwi

/squelch tar clear

/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say Karnor instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/hidec all

/hidec looted





/return



Sub ZoneSleeper



:zone

/if (${Zone.ID}!=128) {

 /say #peqzone 128

 /delay 30s ${Zone.ID}==128

 /goto :zone

 }

/delay 5s



:Caridwi

/squelch tar clear

/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say sleeper instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/return







Sub ZoneCrushbone



:zone

/if (${Zone.ID}!=58) {

 /say #peqzone 58

 /delay 30s ${Zone.ID}==58

 /goto :zone

 }

/delay 5s



:Caridwi

/squelch tar clear

/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /delay 1m

 /goto :Caridwi

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /tar Caridwi

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say crushbone instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/hidec all

/hidec looted





/return





Sub ZoneShadowrest



:zone

/if (${Zone.ID}!=202) {

 /say #peqzone 202

 /delay 30s ${Zone.ID}==202

 /goto :zone

 }

/delay 5s



:Horoal

/squelch tar clear

/if (${SpawnCount[NPC Horoal]}<1) {

 /echo No Horoal

 /delay 1m

 /goto :Horoal

 }



/if (${SpawnCount[NPC Horoal]}>0) {

 /tar Horoal

 /warp t

 /delay 1s



 /if (${Target.CleanName.Equal[Horoal Deathdealer]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say ready

 }





/delay 30s ${Zone.ID}==187

/if (${Target.CleanName.Equal[Horoal Deathdealer]}) /goto :Horoal



/hidec all

/hidec looted





/return







Sub ZoneCOM



/if (${Zone.ID}==94) /goto :Caridwi



:zone

/if (${Zone.ID}!=94) {

 /say #peqzone 94

 /delay 30s ${Zone.ID}==94

 /goto :zone

 }

/delay 2s



:Caridwi

/squelch tar clear

/delay 5s ${SpawnCount[npc Caridwi]}>0
/if (${SpawnCount[npc Caridwi]}<1) {

 /echo No Caridwi

 /call ZoneNexus

 /delay 1m

 /goto :zone

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /warp loc ${Math.Calc[${NearestSpawn[npc Caridwi].Y}-3]} ${Math.Calc[${NearestSpawn[npc Caridwi].X}-3]} ${NearestSpawn[npc Caridwi].Z}

 /delay 1s

 /tar Caridwi

 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say com instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/hidec all

/hidec looted





/return



Sub ZoneNexus



:zone

/if (${Zone.ID}!=152) {

 /say #peqzone 152

 /delay 30s ${Zone.ID}==152

 /goto :zone

 }



/return



Sub ZoneDroga



/if (${Zone.ID}==81) /goto :Caridwi



:zone

/if (${Zone.ID}!=81) {

 /say #peqzone 81

 /delay 30s ${Zone.ID}==81

 /goto :zone

 }

/delay 3s



:Caridwi

/squelch tar clear


/delay 20s ${SpawnCount[npc Caridwi]}
/if (${SpawnCount[npc Caridwi]}<1) {

 /echo No Caridwi

 /call ZoneNexus

 /delay 1m

 /goto :zone

 }



/if (${SpawnCount[npc Caridwi]}>0) {

 |/warp loc ${Math.Calc[${NearestSpawn[npc Caridwi].Y}-3]} ${Math.Calc[${NearestSpawn[npc Caridwi].X}-3]} ${NearestSpawn[npc Caridwi].Z}
 /warp loc 1295 274 4
 /delay 1s

 /tar Caridwi

 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s


 }



 |/say droga instance
 /call DrogaChoose
/doevents
 }
/delay 1s
/doevents
/delay 1s
/doevents




/delay 3s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi







/return



Sub ZoneSeb



:Seb

/if (${Zone.ID}!=89) {

 /say #peqzone 89

 /delay 30s ${Zone.ID}==89

 /goto :Seb

 }

/delay 5s



:Trak

/if (${SpawnCount[NPC Caridwi]}) /goto :Caridwi

/if (!${SpawnCount[NPC Trak nopcnear 100]}) {

 /echo Waiting on trak

 /delay 30s

 /goto :Trak

 }



/if (${SpawnCount[NPC Trak nopcnear 100]}) {

 /warp wp Trak

 /delay 1s

 /tar npc trak

 }



:killtrak

 /if (${Target.CleanName.Equal[Trakanon]}) {

 /killthis

 /delay 2s

 /goto :killtrak

 }



/delay 5s



:Caridwi

/squelch tar clear



/if (!${SpawnCount[NPC Caridwi]}) {

 /echo No Caridwi

 /delay 30s

 /goto :trak

 }



/if (${SpawnCount[NPC Caridwi]}) {

 /warp wp Caridwi

 /delay 1s

 /tar Caridwi

 

 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }



 /say sebilis instance

 }



/delay 1s

/doevents

/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi



/varset AlertTimer 170m

/return





Sub ZoneSAD

/declare sadcount int

:Wait

/if (${SADTimer} || ${ShitTimer}) {

 /delay 5m

 /goto :Wait

 }





:zone

/if (${Zone.ID}==404) /goto :Caridwi

/if (${Zone.ID}!=403 && ${Zone.ID}!=404) {

 /say #peqzone 403

 /delay 30s ${Zone.ID}==403

 /goto :zone

 }

/delay 2s



:Hranath

/warp wp 1

/squelch /tar clear

/delay 2s

/tar Hra

/delay 1s

/if (${Target.CleanName.Equal[Hranath Velentok]}) {

 /hail

 /delay 1s

 /say Long live the legions

 /delay 1s

 }



/if (${Zone.ID}!=404) {

 /delay 30s ${Zone.ID}==404

 /goto :Hranath

 }



:Caridwi

/varcalc sadcount ${sadcount}+1

/if (${sadcount}==5) {

 /say #peqzone 151

 /delay 30s

 /varset sadcount 0

 /goto :Wait

 }



/squelch /tar clear



/if (${SpawnCount[NPC Caridwi]}<1) {

 /echo No Caridwi

 /call ZoneNexus

 /delay 1m

 /goto :zone

 }



/if (${SpawnCount[NPC Caridwi]}>0) {

 /warp loc ${Math.Calc[${NearestSpawn[npc Caridwi].Y}-3]} ${Math.Calc[${NearestSpawn[npc Caridwi].X}-3]} ${NearestSpawn[npc Caridwi].Z}

 /delay 1s

 /tar Caridwi

 /if (${Target.CleanName.Equal[Caridwi]}) {

 /face fast nolook

 /stick 7 moveback

 /delay 1s

 }

 /hail

 /delay 1s

 /say certain requirements

 /delay 1s

 /say Random Instance

 }





/delay 30s ${SpawnCount[NPC range 80 90]}>10

/if (${Target.CleanName.Equal[Caridwi]}) /goto :Caridwi

/varset SADTimer 120m

/varset sadcount 0

/mac a2 1 900000 soi dein win

/return





Sub BloodyKithicor



:Start

/echo 1

/if (${Zone.ID}==210) /goto :Potime

/if (${Zone.ID}==459) /goto :VoidA

/if (${Zone.ID}==456) /goto :BloodyKith



:PotimeA

/if (${Zone.ID}!=219) {

 /say #peqzone 219

 /delay 30s ${Zone.ID}==219

 /goto :PotimeA

 }



:Potime

/delay 5s
/nomodkey /keypress home
/warp loc -39.78 68.08 7.15

/delay 7
/nomodkey /keypress home
/face fast heading 55.20
/delay 2
/click left center
/doortarget

/delay 5
/click left center
/face door nolook

/delay 1s
/click left center
/keypress USE



:Void

/if (${Zone.ID}!=459) {

 /delay 30s ${Zone.ID}==459

 /goto :Void

 }

/delay 2s



:VoidA

/speed 0

/warp loc -34.28 -85.98 8.39

/delay 5

/face loc -38.34, -90.69 nolook

/delay 2s

/keypress forward hold

/delay 2s

/keypress forward



:BloodyKith

/if (${Zone.ID}!=456) {

 /delay 30s ${Zone.ID}==456

 /goto :BloodyKith

 }



/delay 2s



/if (${Zone.ID}==456) {

 /echo We have arrived.

 /goto :here

 }



/speed 5

/goto :start

:here

/return





Sub ZoneOC



:Start

/if (${Zone.ID}==210) /goto :Potime

/if (${Zone.ID}==459) /goto :VoidA

/if (${Zone.ID}==456) /goto :BloodyKith



:PotimeA

/if (${Zone.ID}!=219) {

 /say #peqzone 219

 /delay 30s ${Zone.ID}==219

 /goto :PotimeA

 }



:Potime

/delay 5s
/nomodkey /keypress home
/warp loc -39.78 68.08 7.15
/delay 7
/face fast heading 55.20
/delay 2
/click left center

/doortarget

/delay 5
/click left center
|/face door nolook

/delay 1s
/click left center
/keypress USE



:Void

/if (${Zone.ID}!=459) {

 /delay 30s ${Zone.ID}==459

 /goto :Void

 }

/delay 2s



:VoidA

/speed 0

/warp loc -34.28 -85.98 8.39

/delay 5

|/face loc -38.34, -90.69 nolook
/face fast heading 229.24
/delay 3

/keypress forward hold

/delay 2s

/keypress forward



:BloodyKith

/if (${Zone.ID}!=456) {

 /delay 30s ${Zone.ID}==456

 /goto :BloodyKith

 }



/delay 2s



/if (${Zone.ID}==456) {

 /echo We have arrived.

 /goto :OC

 }



/speed 5



:OC

/warp loc 855.07 -3094.03 23.57

/delay 5

|/face loc 855.07, -3098 nolook
/face heading 270
/delay 5

/keypress forward hold

/delay 2s

/keypress forward



:zone

/if (${Zone.ID}!=457) {

 /delay 30s ${Zone.ID}==457

 /goto :zone

 }



/if (${Zone.ID}==457) {

 /echo We have arrived.

 /goto :here

 }





/goto :start

:here





/return

sub GotoPermafrost

/if (${Zone.ID} != 73) {
	/say #peqzone 73
	/delay 10s !${Me.ID}
	
	/delay 5m ${Me.ID}
	
}
:resay
/tar Caridwi
/warp t

/delay 5

/say permafrost instance

/delay 3s !${Me.ID}
/if (${Me.ID} && ${Zone.ID}==73 && ${SpawnCount[Caridwi]}>0) /goto :resay
/delay 5m ${Me.ID}




/return


Sub ZoneTo(ZoneName)
/if (${Zone.ID} != ${Zone[${ZoneName}].ID}) {
	/say #peqzone ${Zone[${ZoneName}].ID}
	/delay 10s !${Me.ID}
	
	/delay 5m ${Me.ID}
	
}

/return

Sub Event_DrogaZI(Line)

/if (${Zone.ID}==81 && ${Line.Find[First Tier of Droga]}) {
	
	
 
	/if (!${Defined[DrogaInstanceLinks]}) /declare DrogaInstanceLinks[10] string outer 
	/if (!${Defined[DrogaInstanceTier]}) /declare DrogaInstanceTier int outer 0 
	/varset DrogaInstanceTier ${Int[${Math.Calc[(${Line.Count[-]}/2)+1]}]}
	/echo Highest droga tier ${DrogaInstanceTier}
	/delay 1s
	/varset DrogaInstanceLinks[1] ${Line.Mid[${Math.Calc[${Line.Find[First Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[2] ${Line.Mid[${Math.Calc[${Line.Find[Second Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[3] ${Line.Mid[${Math.Calc[${Line.Find[Third Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[4] ${Line.Mid[${Math.Calc[${Line.Find[Fourth Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[5] ${Line.Mid[${Math.Calc[${Line.Find[Fifth Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[6] ${Line.Mid[${Math.Calc[${Line.Find[Sixth Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[7] ${Line.Mid[${Math.Calc[${Line.Find[Seventh Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[8] ${Line.Mid[${Math.Calc[${Line.Find[Eighth Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[9] ${Line.Mid[${Math.Calc[${Line.Find[Ninth Tier of Droga]}-55]},55]}
	/varset DrogaInstanceLinks[10] ${Line.Mid[${Math.Calc[${Line.Find[Tenth Tier of Droga]}-55]},55]}
	/call DrogaTierZoneIn
	
}
/return

Sub SetDrogaLevel
/call CheckDrogaLevel 106 10
/call CheckDrogaLevel 104 9
/call CheckDrogaLevel 102 8
/call CheckDrogaLevel 100 7
/call CheckDrogaLevel 98 6
/call CheckDrogaLevel 96 5
/call CheckDrogaLevel 94 4
/call CheckDrogaLevel 92 3
/call CheckDrogaLevel 90 2
/call CheckDrogaLevel 88 1

/echo Droga Tier set to ${DrogaInstanceTier} and AntiBot Level to ${AntiDrogaMobLevel}

/return

Sub CheckLoreItem(itemID)
/declare bankSlot int local
/declare containerSlot int local


/for bankSlot 23 to 30
	/if (${Me.Inventory[${bankSlot}].Container}>0) {
		/for containerSlot 1 to ${Me.Inventory[${bankSlot}].Container}
			/if (${Me.Inventory[${bankSlot}].Item[${containerSlot}].ID}==${itemID}) /return 1
		/next containerSlot
	} else {
		
		/if (${Me.Inventory[${bankSlot}].ID}==${itemID}) /return 1
	}

/next bankSlot

/for bankSlot 1 to 24
	
	/if (${Me.Bank[${bankSlot}].Container}>0) {
		/for containerSlot 1 to ${Me.Bank[${bankSlot}].Container}
			/if (${Me.Bank[${bankSlot}].Item[${containerSlot}].ID}==${itemID}) /return 1
		/next containerSlot
	} else {
		
		/if (${Me.Bank[${bankSlot}].ID}==${itemID}) /return 1
	}
/next bankSlot

/return 0

Sub CheckDrogaLevel(level, tier)

/if (!${Defined[AntiDrogaMobLevel]}) /declare AntiDrogaMobLevel int outer 105
/if (${SpawnCount[npc range ${level} ${level}]} > 0 ) {
	/varset DrogaInstanceTier ${tier}
	/if (${DrogaInstanceTier} == 1) {
	/varset AntiDrogaMobLevel 105
	} else {
	/varset AntiDrogaMobLevel ${Math.Calc[105+(${DrogaInstanceTier}*2)]}
	}
	
}
/return

|droga Caridwi Choose link B88C000000000000000000000000000000000000000000000000000
|droga 1 Level link  B8F3D00000000000000000000000000000000000000000000000000 88  105
|droga 2 Level link  B8F3E00000000000000000000000000000000000000000000000000 90  107
|droga 3 Level link  B8F3F00000000000000000000000000000000000000000000000000 92  109
|droga 4 Level link  B8F4000000000000000000000000000000000000000000000000000 94  111
|droga 5 Level link  B8F4100000000000000000000000000000000000000000000000000 96  113
|droga 6 Level link  B8F4200000000000000000000000000000000000000000000000000 98  115
|droga 7 Level link  B8F4300000000000000000000000000000000000000000000000000 100 117
|droga 8 Level link  B8F4400000000000000000000000000000000000000000000000000 102 119
|droga 9 Level link  B8F4500000000000000000000000000000000000000000000000000 104 121
|droga 10 Level link B846D00000000000000000000000000000000000000000000000000 106 123
Sub DrogaChoose
	/echo Clicking Choose Link
	/notify ChatWindow CW_ChatOutput link B88C000000000000000000000000000000000000000000000000000
	/delay 5
	/doevents
/return

Sub DrogaTierZoneIn
	
	/if (!${Defined[DrogaSelectedInstanceTier]}) {
		/notify ChatWindow CW_ChatOutput link ${DrogaInstanceLinks[${DrogaInstanceTier}]}
	} else {
		/notify ChatWindow CW_ChatOutput link ${DrogaInstanceLinks[${DrogaSelectedInstanceTier}]}
	}
/return


Sub LdonCamp

/if (${Zone.ID}==68) {
	/warp loc -1085 -2484 -0.8
	/face fast heading 304
	/delay 5
	/target Kroggl
}

|East Commons
/if (${Zone.ID}==22) {
	/warp loc -1655 -162 2.5
	/face fast heading 267
	/delay 5
	/target Uzmanya
}

|North Ro
/if (${Zone.ID}==34) {
	/warp loc 2665 908 -26
	/face fast heading 228
	/delay 5
	/target Efrelle
}
/return

Sub LdonEntrance
|lfaydark 
/if (${Zone.ID}==57) {
	|ldon1 ... the old crypt in the South Western corner.
	/warp loc -759 3836 1.22
	/face fast heading 113
	/look -50

	|ldon1 ...
	/warp loc -113 3879 -38.70
	/face fast heading 180
	/look -50
}

|south ro
/if(${Zone.ID}==35) {
	/warp loc -2113 1346 -82
	/face fast heading 0
	/look 0
}

|North ro
/if(${Zone.ID}==34) {
	/warp loc -954 123 -62
	/face fast heading 224
	/look -100
}

/return