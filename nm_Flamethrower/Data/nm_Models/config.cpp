class CfgPatches
{
	class nm_Flamethrower_Model
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"DZ_Data",
			"DZ_Scripts"
		};
	};
};

class Mode_Safe;
class Mode_Single;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class OpticsInfoPistol;
class OpticsInfoRifle;
class OpticsInfoShotgun;
class cfgWeapons
{
	class Rifle_Base;
	class nm_Flamethrower_Base: Rifle_Base
	{
		scope=0;
		weight=7500;
		absorbency=0;
		repairableWithKits[]={1};
		repairCosts[]={25};
		PPDOFProperties[]={0,0,0,0,0,0};
		WeaponLength=0.77999997;
		barrelArmor=2.4000001;
		chamberSize=1;
//		chamberedRound="";
		chamberableFrom[]={"nm_Ammo_Gasoline"};
		magazineSwitchTime=0.38;
		ejectType=0;
		recoilModifier[]={1,1,1};
		swayModifier[]={1,5,1,5,1};
		modes[]=
		{
			"FullAuto"
		};
		magazines[]=
		{
			"nm_ScrapCanister_Mag"
		};
		attachments[]=
		{
			"weaponWrap"
		};		
		class FullAuto: Mode_FullAuto
		{
			soundSetShot[]=
			{
				"",
				"",
				""
			};
			reloadTime=0.064999998;
			recoil="recoil_single_primary_1outof10";
			recoilProne="recoil_single_primary_1outof10";
			dispersion=0.090000004;
			magazineSlot="magazine";
		};
		class NoiseShoot
		{
			strength=0;
			type="sound";
		};
		class Particles
		{
			class OnFire
			{
				class SmokeCloud
				{
					overrideParticle="weapon_shot_winded_smoke";
				};
				class MuzzleFlash
				{
					overrideParticle="weapon_shot_akm_01";
					ignoreIfSuppressed=1;
					illuminateWorld=1;
					positionOffset[]={-0.050000001,0,0};
				};
				class ChamberSmokeBurst
				{
					overrideParticle="weapon_shot_chamber_smoke";
					overridePoint="Nabojnicestart";
					overrideDirectionPoint="Nabojniceend";
				};
			};
			class OnOverheating
			{
				maxOverheatingValue=60;
				shotsToStartOverheating=25;
				overheatingDecayInterval=1;
				class SmokingBarrel1
				{
					overrideParticle="smoking_barrel_small";
					onlyWithinOverheatLimits[]={0,0.5};
					positionOffset[]={0.1,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot1
				{
					overrideParticle="smoking_barrel";
					onlyWithinOverheatLimits[]={0.5,0.80000001};
					positionOffset[]={0.1,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHot3
				{
					overrideParticle="smoking_barrel_heavy";
					onlyWithinOverheatLimits[]={0.80000001,1};
					positionOffset[]={0.1,0,0};
					onlyWithinRainLimits[]={0,0.2};
				};
				class SmokingBarrelHotSteamSmall
				{
					overrideParticle="smoking_barrel_steam_small";
					positionOffset[]={0.30000001,0,0};
					onlyWithinRainLimits[]={0.2,0.5};
				};
				class SmokingBarrelHotSteam
				{
					overrideParticle="smoking_barrel_steam";
					positionOffset[]={0.30000001,0,0};
					onlyWithinRainLimits[]={0.5,1};
				};
				class OpenChamberSmoke
				{
					onlyIfBoltIsOpen=1;
					overrideParticle="smoking_barrel_small";
					overridePoint="Nabojnicestart";
				};
			};
			class OnBulletCasingEject
			{
				class ChamberSmokeRaise
				{
					overrideParticle="weapon_shot_chamber_smoke_raise";
					overridePoint="Nabojnicestart";
				};
			};
		};
		weaponStateAnim="dz\anims\anm\player\reloads\AKM\w_AKM_states.anm";		
	};
	class nm_Flamethrower: nm_Flamethrower_Base
	{
		scope=2;
		displayName="$STRnmFlamethrower";
		descriptionShort="$STRnmFlamethrowerDisc";
		model="nm_Flamethrower\data\nm_Models\nm_Flamethrower.p3d";
		itemSize[]={10,3};
		weight=3300;
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"nm_Flamethrower\data\nm_Models\data\PLACEHOLDER.paa"
		};
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 200;
                };
            };
		};
	};
};

class CfgMagazines
{
	class Magazine_Base;
	class nm_ScrapCanister_Mag: Magazine_Base
	{
		scope=2;
		rotationFlags=4;
		weight=150;
		itemSize[]={3,4};
		displayName="$STRnmScrapCanister";
		descriptionShort="$STRnmScrapCanisterDisc";
		model = "nm_Flamethrower\data\nm_Models\nm_ScrapCanister_Magazine.p3d";
		hiddenSelections[]=
		{
			"zbytek"
		};
		hiddenSelectionsTextures[]=
		{
			"nm_Flamethrower\data\nm_Models\data\PLACEHOLDER_MAG.paa"
		};
		tracersEvery=0;
		ammo="Bullet_nm_Gasoline";
		ammoItems[]=
		{
			"nm_Ammo_Gasoline"
		};
		countType = "Quantity";
		varQuantityMin=0;
		varQuantityMax=200;
		quantityBar=1;
		destroyOnEmpty=0;
		varQuantityDestroyOnMin=0;
		count=200;
		stackedUnit="ml";
		soundImpactType="metal";
		class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints = 100;
                };
            };
		};
	};
	class Ammunition_Base;
	class nm_Ammo_Gasoline: Ammunition_Base
	{
		scope=2;
		displayName="Gasoline Ammo";
		descriptionShort="Test";
		iconCartridge=1;
		weight=200;
		itemSize[]={1,1};
		count=500;
		ammo="Bullet_nm_Gasoline";
	};
};
class cfgAmmoTypes
{
	class AType_Bullet_nm_Gasoline
	{
		name="Bullet_nm_Gasoline";
	};
};
class cfgAmmo
{
	class DefaultAmmo;
	class Bullet_Base;
	class Bullet_nm_Gasoline: Bullet_Base
	{		
		scope=2;
		hit=8;
		indirectHit=0;
		indirectHitRange=0;
		impactBehaviour=0;
		hitAnimation=0;
		model="\dz\weapons\projectiles\empty.p3d";
		proxyShape="nm_Flamethrower\data\nm_Models\nm_Bullet_Gasoline.p3d";
//		simulation="shotIlluminating"; 							This seems to not work engine sided?
//		SimulationScriptClass="nm_FlamethrowerSimulation";		This seems to not work engine sided?
		projectilesCount=5;
		airLock=0;
		deflecting=50;
		dispersion=0.050000001;
		initSpeed=340;
		typicalSpeed=340;
		caliber=1.1900001;
		airFriction=-0.0099999998;
		damageBarrel=80;
		damageBarrelDestroyed=80;
		weight=0.0; ///was 0.0049999999
		timeToLive= 0.035; ///was 0.035
		unconRefillModifier=4;
		spawnPileType="nm_Ammo_Gasoline";
		class DamageApplied
		{
			type="Projectile";
			dispersion=0;
			bleedThreshold=1;
			defaultDamageOverride[]=
			{
				{0.5,1}
			};
			class Health
			{
				damage=5;
				armorDamage=3;
			};
			class Blood
			{
				damage=0;
			};
			class Shock
			{
				damage=5;
			};
		};		
		class NoiseHit
		{
			strength=0;
			type="shot";
		};
		soundFly[]=
		{
			"",
			0,
			0
		};
		soundDefault1[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault2[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault3[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault4[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault5[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault6[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault7[]=
		{
			"",
			0,
			0,
			0
		};
		soundDefault8[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft1[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft2[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft3[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft4[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft5[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft6[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft7[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundSoft8[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard1[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard2[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard3[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard4[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard5[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard6[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard7[]=
		{
			"",
			0,
			0,
			0
		};
		soundGroundHard8[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal1[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal2[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal3[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal4[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal5[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal6[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal7[]=
		{
			"",
			0,
			0,
			0
		};
		soundMetal8[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass1[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass2[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass3[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass4[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass5[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass6[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass7[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlass8[]=
		{
				"",
			0,
			0,
			0
		};
		soundGlassArmored1[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlassArmored2[]=
		{
			"",
			0,
			0,
			0
		};
		soundGlassArmored3[]=
		{			
			"",
			0,
			0,
			0
		};
		soundGlassArmored4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundGlassArmored5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundGlassArmored6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundGlassArmored7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundGlassArmored8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundVehiclePlate8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWood8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBody8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitBuilding8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundHitFoliage8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundPlastic8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundConcrete8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundRubber8[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater1[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater2[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater3[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater4[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater5[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater6[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater7[]=
		{		
			"",
			0,
			0,
			0
		};
		soundWater8[]=
		{		
			"",
			0,
			0,
			0
		};
		hitGroundSoft[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitGroundHard[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitMan[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitArmor[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitBuilding[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitFoliage[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitWood[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitGlass[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitGlassArmored[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitConcrete[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitRubber[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitPlastic[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitDefault[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitMetal[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitMetalplate[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		hitWater[]=
		{
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
			"",
			0,
		};
		soundSetBulletFly[]=
		{
			""
		};
		soundSetSuperSonic[]=
		{
			"",
			""
		};
	};
};