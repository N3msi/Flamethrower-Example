// Fills Magazine from Bottle_Base

class FillnmScrapCanister1 extends RecipeBase
{	
	override string GetSoundCategory(int ingredientIndex, ItemBase item)
	{
		return "nm_Fill";
	}
	
	override void Init()
	{
		m_Name = "#refuel";
		m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
		m_AnimationLength = 1.0;//animation length in relative time units
		m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision
		
		
		//conditions
		m_MinDamageIngredient[0] = -1;//-1 = disable check
		m_MaxDamageIngredient[0] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[0] = 1;//-1 = disable check
		m_MaxQuantityIngredient[0] = -1;//-1 = disable check
		
		m_MinDamageIngredient[1] = -1;//-1 = disable check
		m_MaxDamageIngredient[1] = 3;//-1 = disable check
		
		m_MinQuantityIngredient[1] = -1;//-1 = disable check
		m_MaxQuantityIngredient[1] = -1;//-1 = disable check
		//----------------------------------------------------------------------------------------------------------------------
		
		//INGREDIENTS
		//ingredient 1
		InsertIngredient(0,"Bottle_Base");//you can insert multiple ingredients this way

		m_IngredientAddHealth[0] = 0;// 0 = do nothing
		m_IngredientSetHealth[0] = -1; // -1 = do nothing
		m_IngredientAddQuantity[0] = 0;// 0 = do nothing
		m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
		m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		
		//ingredient 2
		InsertIngredient(1,"nm_ScrapCanister_Mag");//you can insert multiple ingredients this way
		
		m_IngredientAddHealth[1] = 0;// 0 = do nothing
		m_IngredientSetHealth[1] = -1; // -1 = do nothing
		m_IngredientAddQuantity[1] = 0;// 0 = do nothing
		m_IngredientDestroy[1] = false;// false = do nothing
		m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
		//----------------------------------------------------------------------------------------------------------------------
	}

	override bool CanDo( ItemBase ingredients[], PlayerBase player )//final check for recipe's validity
	{
		Magazine_Base ScrapCanister = Magazine_Base.Cast(ingredients[1]);
		ItemBase Gasoline = ingredients[0];
		
		//Do not fill if not gasoline
		if(Gasoline.GetLiquidType() != LIQUID_GASOLINE )
			return false;
		
		//Do not fill if alread full 
		if(ScrapCanister.GetAmmoCount() >= ScrapCanister.GetAmmoMax())
		{
			return false;
		}				
		return true;
		
	}

	override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)//gets called upon recipe's completion
	{
		// Get Gasoline quantity
		ItemBase Gasoline = ingredients[0];    
		float GasolineCurrent = Gasoline.GetQuantity();
		
		// Get ScrapCanister AmmoCount
		Magazine_Base ScrapCanister = Magazine_Base.Cast(ingredients[1]);
		float ScrapCanisterMaxA = ScrapCanister.GetAmmoMax();
		float ScrapCanisterCurrentA = ScrapCanister.GetAmmoCount();
		
		float fillAmountA = ScrapCanisterMaxA - ScrapCanisterCurrentA;
		if (GasolineCurrent < fillAmountA) 
		{
			fillAmountA = GasolineCurrent;
		}
		
		// Multiply fillAmountA
		float drainAmountA = fillAmountA * 5;	
	
		// Fill ScrapCanister
		if (fillAmountA > 0) 
		{
			ScrapCanister.ServerAddAmmoCount(fillAmountA);
			Gasoline.AddQuantity(-drainAmountA);
		}
	}
};
