modded class PluginRecipesManagerBase extends PluginBase
{
	override void RegisterRecipies()
	{
		super.RegisterRecipies();
		
		RegisterRecipe(new FillnmScrapCanister1); /// Fill ScrapCanister from bottle	
    }       
};