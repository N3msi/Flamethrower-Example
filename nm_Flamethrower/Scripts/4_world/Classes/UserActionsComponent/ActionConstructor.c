modded class ActionConstructor
{	
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);  ///
		
   		actions.Insert(ActionnmRefuelnmCanisterFromPump);  /// fill Scrapcanister from Fuel Pump | Item found in Entities/ItemBase/Scrapcanister.c
	}
};  
