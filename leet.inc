

|#event UbaidKills "#*#This makes #1# Deaths#*#"

| <Eclin> OOC from Schween: 0037E0000000000000000000000000000000000000D10C90ECBrazier of Elemental Summoning should have infinite charges right?

Sub ReclaimCurrencyAll

	/declare x int local

	/for x 1 to 16
		
		/nomodkey /notify InventoryWindow AltCurr_PointList listselect ${x}
		/delay 3
		/nomodkey /notify InventoryWindow AltCurr_ReclaimButton leftmouseup
		/delay 3

	/next x
/return
Sub ReclaimCurrency
	
	/call CheckSingleCurrency "Bayle Mark" "Bayle's Mark"
	/call CheckSingleCurrency "Brellium Token" "Brellium Token"
	/call CheckSingleCurrency "Chronobine" "Chronobines"
	/call CheckSingleCurrency "Codex Lesson" "Codex Lessons"
	/call CheckSingleCurrency "Doubloon" "Doubloons"
	/call CheckSingleCurrency "Dream Mote" "Dream Mote"
	/call CheckSingleCurrency "Ebon Crystal" "Ebon Crystal" 
	/call CheckSingleCurrency "Faycetum" "Faycitum"
	/call CheckSingleCurrency "Gold Token" "Gold Token"
	/call CheckSingleCurrency "McKenzie" "McKenzie"
	/call CheckSingleCurrency "Million Platinum Token" "Million Platinum Token"
	/call CheckSingleCurrency "Silver Token" "Silver Token"
	
/return

Sub CheckSingleCurrency(name,listName)

	/if (${FindItemCount[${name}]} > 0 ) /call ReclaimSingleCurrency "${listName}" "name"
/return

Sub ReclaimSingleCurrency(value,name)
	/if (!${Window[InventoryWindow].Open} ) /nomodkey /keypress inventory
	/nomodkey /notify InventoryWindow AltCurr_PointList listselect ${Window[InventoryWindow].Child[AltCurr_PointList].List[${value},2]}
	/delay 1
	/nomodkey /notify InventoryWindow AltCurr_ReclaimButton leftmouseup
	/delay 1s !${FindItemCount[${name}]}

/return

Sub CheckXTarget

	/declare Sum int local
	/declare x int local
	
	/for x 1 to 13
		/if ( ${Me.XTarget[${x}].ID} > 0 && !${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[Untargetable]} && ${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[NPC]}) /varcalc Sum ${Sum}+1
	/next x

/return ${Sum}

Sub AvoidPCPlayer
	/if ( ${Spawn[id ${npcID}].NearestSpawn[pc radius ${pcRadiusAvoid}].ID} > 0 && ${Spawn[id ${npcID}].NearestSpawn[pc radius ${pcRadiusAvoid}].ID}!=${Me.ID}) {
	/echo Skipping to next Target.. mob engaged!
	/declare x int local
	/declare oldTarg int ${npcID}
	
	/for x ${Math.Calc[1+${Math.Rand[5]}]} to ${SpawnCount[npc ${Mob${mo}} radius ${MaxRad} zradius ${MaxZ} targetable  noalert 1 range ${TargMin} ${TargMax} ]}
		 /vardata npcID Spawn[id ${npcID}].NearestSpawn[${x},npc ${Mob${mo}} radius ${MaxRad} zradius ${MaxZ} targetable noalert 1 range ${TargMin} ${TargMax} ].ID
		 /if ( ${npcID} >0 && !${Spawn[id ${npcID}].NearestSpawn[pc radius ${pcRadiusAvoid}].ID}) /return ${npcID}
		 /if ( ${npcID} == 0) {
			/varset npcID ${oldTarg}
			/return 0
		}
		 /varset oldTarg ${npcID}
	/next x
	}

/return 0

Sub GetTargetFromXTarget
	/declare x int local
	/for x 1 to 13
		/if ( ${Me.XTarget[${x}].ID} > 0 && !${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[Untargetable]} && ${Spawn[id ${Me.XTarget[${x}].ID}].Type.Equal[NPC]}) /return ${Me.XTarget[${x}].ID} 
	/next x
/return 0



Sub Event_UbaidKills(Line, numkills)

/echo kills:${numkills}

/ini Leet.ini Ubaid NumKills ${numkills}
/ini Leet.ini Ubaid LastTimer ${Time.Date} ${Time.Time24}


/return

Sub WarpPointOnCircle(spawnID,angle,distance)

	/declare nx float ${Math.Calc[${Spawn[id ${spawnID}].X} + ${distance}*${Math.Cos[${angle}]}]}
	/declare ny float ${Math.Calc[${Spawn[id ${spawnID}].Y} + ${distance}*${Math.Sin[${angle}]}]}

	/warp loc ${ny} ${nx} ${Math.Calc[${Spawn[id ${spawnID}].Z}+1]}
	/delay 1
	/face fast
/return