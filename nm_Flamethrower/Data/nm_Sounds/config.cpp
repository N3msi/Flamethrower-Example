class CfgPatches
{
	class nm_Flamethrower_Sound
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
class CfgSounds
{
	class default
	{
		name="";
		titles[]={};
	};
	class nm_Fill_Sound: default
	{
		sound[]=
		{
			"nm_Flamethrower\data\nm_Sounds\nm_fill",
			2,//was 0.1
			1,
			30
		};
	};
};
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class nm_FT_SoundShaderClose
	{
		samples[]=
		{
			
			{
				"nm_Flamethrower\data\nm_Sounds\nm_FT-Shot",
				1
			}
		};
		volume=0.5;
		range=50;
		rangeCurve="closeShotCurve";
	};
	class nm_FT_SoundShaderMid
	{
		samples[]=
		{
			
			{
				"nm_Flamethrower\data\nm_Sounds\nm_FT-Shot",
				1
			}
		};
		volume=0.40000001;
		range=1500;
		rangeCurve[]=
		{
			{0,0.2},
			{50,1},
			{300,0},
			{1500,0}
		};
	};
	class nm_FT_SoundShaderLong
	{
		samples[]=
		{
			
			{
				"nm_Flamethrower\data\nm_Sounds\nm_FT-Shot",
				1
			}
		};
		volume=0.30000001;
		range=1500;
		rangeCurve[]=
		{
			{0,0},
			{50,0},
			{300,1},
			{1500,1}
		};
	};
};
class CfgSoundSets
{
	class Rifle_Shot_Base_SoundSet;
	class nm_FT_SoundSet: Rifle_Shot_Base_SoundSet
	{
		soundShaders[]=
		{
			"nm_FT_SoundShaderClose",
			"nm_FT_SoundShaderMid",
			"nm_FT_SoundShaderLong"
		};
	};
};
class CfgSoundTables
{
	class CfgActionsSoundTables
	{
		class Craft_LookupTable
		{
			class nm_Fill_loop
			{
				category="nm_Fill";
				soundSets[]=
				{
					"WellBottle_loop_Soundset"
				};
			};
		};
	};
};
