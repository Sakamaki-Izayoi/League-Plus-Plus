﻿#include "Kalista.h"

bool sExtensions::IsFarming()
{
	return Kalista::SDK->GetOrbwalking()->GetOrbwalkingMode() == kModeLaneClear || Kalista::SDK->GetOrbwalking()->GetOrbwalkingMode() == kModeLastHit || Kalista::SDK->GetOrbwalking()->GetOrbwalkingMode() == kModeMixed || Kalista::SDK->GetOrbwalking()->GetOrbwalkingMode() == kModeFreeze;
}

float sExtensions::GetDistance(IUnit* sender, IUnit* target)
{
	return (sender->GetPosition() - target->GetPosition()).Length2D();
}

float sExtensions::GetDistance(Vec3 senderPosition, Vec3 targetPosition)
{
	return (senderPosition - targetPosition).Length2D();
}

float sExtensions::GetRealDistance(IUnit* sender, IUnit* target)
{
	return (sender->ServerPosition() - target->ServerPosition()).Length2D() + sender->BoundingRadius() + target->BoundingRadius();
}

int sExtensions::CountAlliesInTargetRange(IUnit* target, float range)
{
	auto allies = 0;

	for (auto ally : GEntityList->GetAllHeros(true, false))
	{
		if (ally != nullptr && GetDistance(target, ally) <= range)
		{
			allies++;
		}
	}

	return allies;
}

int sExtensions::CountEnemiesInTargetRange(IUnit* target, float range)
{
	auto enemies = 0;

	for (auto enemy : GEntityList->GetAllHeros(false, true))
	{
		if (enemy != nullptr && GetDistance(target, enemy) <= range)
		{
			if (enemy != target)
			{
				enemies++;
			}
		}
	}

	return enemies;
}

int sExtensions::CountMinionsInTargetRange(IUnit* target, float range)
{
	auto minions = 0;

	for (auto minion : GEntityList->GetAllMinions(false, true, false))
	{
		if (minion != nullptr && GetDistance(target, minion) <= range)
		{
			if (minion != target && !minion->IsDead())
			{
				minions++;
			}
		}
	}

	return minions;
}