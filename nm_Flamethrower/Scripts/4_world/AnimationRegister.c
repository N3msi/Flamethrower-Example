modded class ModItemRegisterCallbacks
{
	override void RegisterFireArms(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterFireArms(pType, pBehavior);
        pType.AddItemInHandsProfileIK("nm_Flamethrower_Base", "dz/anims/workspaces/player/player_main/weapons/player_main_akm.asi", pBehavior, "dz/anims/anm/player/ik/weapons/akm.anm", "dz/anims/anm/player/reloads/akm/w_akm_states.anm");

	}
	override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded(pType, pBehavior);
		
		pType.AddItemInHandsProfileIK("nm_ScrapCanister_Mag", "dz/anims/workspaces/player/player_main/props/player_main_STANAG_mag.asi", pBehavior, "dz/anims/anm/player/ik/gear/gascannisterlarge.anm");
		
    }
}
