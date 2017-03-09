﻿#include "sMenu.h"

sMenu::sMenu(IMenu* menu)
{
	Main = menu;
	{
		Draw = Main->AddMenu("Drawings");
		{
			DrawQ = Draw->CheckBox("Draw Q", true);
			DrawW = Draw->CheckBox("Draw W", false);
			DrawE = Draw->CheckBox("Draw E", true);
			DrawEDamage = Draw->CheckBox("Draw E Damage", true);
			DrawR = Draw->CheckBox("Draw R", true);
			DrawReady = Draw->CheckBox("Draw only if spell is ready", true);
		}

		Q = Main->AddMenu("Q Settings");
		{
			QCombo = Q->CheckBox("Combo Q", true);
			QComboMinion = Q->CheckBox("Combo Q Minions", true);
			QHarass = Q->CheckBox("Harass Q", true);
			QClear = Q->CheckBox("Clear Q", true);
			QClearMinimum = Q->AddInteger("^-> Minimum kill {x} minions", 1, 7, 3);
			QFarmOutOfRange = Q->CheckBox("Lasthit unkillible minions w/o stacks", false);
		}

		W = Main->AddMenu("W Settings");
		{
			WDragonKey = W->AddKey("Sentinel Dragon", 89);
			WBaronKey = W->AddKey("Sentinel Baron", 84);
		}

		E = Main->AddMenu("E Settings");
		{
			ECombo = E->CheckBox("Combo E", true);
			EBeforeDeath = E->CheckBox("^-> Auto E before death", true);
			EOutOfRange = E->CheckBox("^-> Auto E leaving", true);
			EOutOfRangeMinimum = E->AddInteger("	^-> Minimum {x}% damage while leaving", 1, 50, 10);
			EHarass = E->CheckBox("Harass E", true);
			ELastHitUnkillable = E->CheckBox("LastHit unkillable minions", true);
			ELaneClear = E->CheckBox("Clear E", true);
			ELaneClearMinimum = E->AddInteger("^-> Minimum kill {x} minions", 2, 10, 4);
		}

		R = Main->AddMenu("R Settings");
		{
			RSaveAlly = R->CheckBox("Use R to save ally", true);
			RSaveAllyHealth = R->AddInteger("^-> at {x}% health", 1, 100, 20);
		}
	}
}