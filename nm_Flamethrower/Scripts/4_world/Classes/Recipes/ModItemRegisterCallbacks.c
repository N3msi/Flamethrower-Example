modded class ModItemRegisterCallbacks
{

    override void RegisterHeavy(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
		pType.AddItemInHandsProfileIK("FillnmScrapCanister1", "dz/anims/workspaces/player/player_main/player_main_heavy.asi", pBehavior,    "dz/anims/anm/player/ik/heavy/55galDrum.anm"); 
	    super.RegisterHeavy(pType, pBehavior);
    }

}