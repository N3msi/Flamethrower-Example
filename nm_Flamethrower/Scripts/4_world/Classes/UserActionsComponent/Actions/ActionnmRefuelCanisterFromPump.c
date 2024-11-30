///Fills Magazine from Land_FuelStation_Feed

class ActionnmRefuelnmCanisterFromPumpCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
	{
		m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.ADD_FUEL_TO_TORCH);
	}
};

class ActionnmRefuelnmCanisterFromPump: ActionContinuousBase
{	
	void ActionnmRefuelnmCanisterFromPump()
	{
		m_CallbackClass = ActionnmRefuelnmCanisterFromPumpCB;
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_EMPTY_VESSEL;
		m_FullBody = true;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_LOW;
		m_Text = "#refuel";
		m_Sound = "nm_Fill_Sound";
	}
	
	override void CreateConditionComponents()  
	{	
		
		m_ConditionTarget = new CCTDummy;
		m_ConditionItem = new CCINonRuined;
	}

	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{
		if (!target || !item || !target.GetObject())
			return false;

		// Check if target is Land_FuelStation_Feed
		if (target.GetObject().IsKindOf("Land_FuelStation_Feed"))
		{
			Land_FuelStation_Feed fuelStation = Land_FuelStation_Feed.Cast(target.GetObject());

			// Check if fuel station is functional
			if (fuelStation.HasFuelToGive())
			{
				// Check if the item Magazine_Base
				if (item.IsKindOf("Magazine_Base"))
				{
					Magazine_Base canister = Magazine_Base.Cast(item);
					return canister.GetAmmoCount() < canister.GetAmmoMax();
				}
			}
		}

		return false;
	}

	override void OnFinishProgressServer(ActionData action_data)
	{
		ItemBase item = action_data.m_MainItem;
		if (item && item.IsKindOf("Magazine_Base"))
		{
			Magazine_Base canister = Magazine_Base.Cast(item);
			int fillAmount = canister.GetAmmoMax() - canister.GetAmmoCount();
			canister.ServerAddAmmoCount(fillAmount);
		}
	}
};
