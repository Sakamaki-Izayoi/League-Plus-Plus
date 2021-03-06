#include "PluginSDK.h"

enum eMinionType
{
	kMinionUnknown = 0,
	kMinionWard = (1 << 0),
	kMinionNormal = (1 << 1),
	kMinionSiege = (1 << 2),
	kMinionSuper = (1 << 3),
	kMinionJungleSmall = (1 << 4),
	kMinionJungleBig = (1 << 5),
	kMinionJungleEpic = (1 << 6)
};

class IExtension
{
public:
	static std::string format(const char* format, ...);
	static void CheckVersion(char* name, int version);
	static ITexture* GetTexture(char* name);
	static bool TextureExists(char* name);
	static int GetDangerLevel(IUnit* hero);
	static bool IsComboing();
	static bool IsHarassing();
	static bool IsClearing();
	static bool IsLasthitting();
	static bool IsFarming();
	static float GetDistance(IUnit* sender, IUnit* target);
	static float GetDistance(Vec3 senderPosition, Vec3 targetPosition);
	static float GetRealDistance(IUnit* sender, IUnit* target);
	static int CountAliesInRange(float range);
	static int CountEnemiesInRange(float range);
	static int CountAlliesInPositionRange(Vec3 position, float range);
	static int CountEnemiesInPositionRange(Vec3 position, float range);
	static int CountMinionsInPositionRange(Vec3 position, float range);
	static int CountAlliesInTargetRange(IUnit* target, float range);
	static int CountEnemiesInTargetRange(IUnit* target, float range);
	static int CountMinionsInTargetRange(IUnit* target, float range);
	static Vec3 GetSpawnPosition(IUnit* hero);
	static eMinionType GetMinionType(IUnit* minion);
};

extern IExtension* GExtension;