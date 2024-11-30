class CfgPatches
{
	class nm_Flamethrower
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
class CfgMods
{
	class nm_Flamethrower
	{
		dir="nm_Flamethrower";
		name="nm_Flamethrower";
		credits="n3msi";
		author="n3msi";
		authorID="0";
		version="1.25";
		extra=0;
		type="mod";
		class defs
		{	
			class gameScriptModule
			{
				value="";
				files[]=
				{
					"nm_Flamethrower/scripts/3_game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[]=
				{
					"nm_Flamethrower/scripts/4_World"
				};
			};
			class missionScriptModule
			{
				value="";
				files[]=
				{
					"nm_Flamethrower/scripts/5_Mission"
				};
			};
		};
	};
};