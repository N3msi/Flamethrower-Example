///change HUD-bulletcount to quantitybar
modded class ItemActionsWidget extends ScriptedWidgetEventHandler 
{
	override protected override void SetWeaponQuantity(int chamber, int mag, string itemWidget, string quantityPBWidget, string quantityTextWidget, bool enabled)
	{		
		Widget widget;
		
		widget = m_Root.FindAnyWidget(itemWidget);
		
		if (enabled)
		{
			string wpn_qty = "";

			ProgressBarWidget progressBar;
			TextWidget textWidget;
			Class.CastTo(progressBar, widget.FindAnyWidget(quantityPBWidget));
			Class.CastTo(textWidget, widget.FindAnyWidget(quantityTextWidget));
			
			Weapon_Base wpn;
			Magazine maga;
			int mag_quantity = -1;
			int mag_nmshown = -1;
			
			if (!Class.CastTo(wpn, m_EntityInHands)) 
			{
			return;
			}

			progressBar.Show(false);
			
			if (Class.CastTo(wpn, m_EntityInHands))
			{
				if (nm_Flamethrower_Base.Cast(wpn))	
                {
                   	for (int nmi = 0; nmi < wpn.GetMuzzleCount(); nmi++)
                    {
                        Magazine FTmag = wpn.GetMagazine(nmi);
                        if (FTmag && FTmag.IsInherited(nm_ScrapCanister_Mag))
                        {				
                            mag_quantity = FTmag.GetAmmoCount();
							mag_nmshown = mag_quantity*0.5;
						}
						progressBar.SetCurrent(mag_nmshown);
                        progressBar.Show(true);
                        textWidget.Show(false);
                        return;
                    }
                }
				else if (Magnum_Base.Cast(wpn))
				{
					mag_quantity = 0;
					for (int j = 0; j < wpn.GetMuzzleCount(); j++)
					{
						if (wpn.IsChamberFull(j)&& !wpn.IsChamberFiredOut(j))
							mag_quantity++; 
					}
					wpn_qty = mag_quantity.ToString();
				}
				else
				{
					for (int i = 0; i < wpn.GetMuzzleCount(); i++)
					{
						if (i > 0 && (wpn.GetMuzzleCount() < 3 ||  i%2 == 0))
						{
							wpn_qty = wpn_qty + " ";
						}
						if (wpn.IsChamberEmpty(i))
						{
							wpn_qty = wpn_qty + "0";
						}
						else if (wpn.IsChamberFiredOut(i))
						{
							wpn_qty = wpn_qty + "F";
						}
						else
						{
							wpn_qty = wpn_qty + "1";
						}
						
						maga = wpn.GetMagazine(i);
						if (maga)
						{
							mag_quantity = maga.GetAmmoCount();
						}
						else if (wpn.GetInternalMagazineMaxCartridgeCount(i) > 0)
						{
							mag_quantity = wpn.GetInternalMagazineCartridgeCount(i);
						}
					
					}
				
					if (wpn.IsJammed())
					{
						if (mag_quantity != -1)
							wpn_qty = string.Format("X (+%1)", mag_quantity);
						else
							wpn_qty = "X";
					}
					else
					{
						if (mag_quantity != -1)
						{
							wpn_qty = wpn_qty + " (" + mag_quantity.ToString() + ")";
						}
					}
				}
			}
	
			progressBar.Show(false);
			textWidget.SetText(wpn_qty);
			textWidget.Show(true);
			textWidget.GetParent().Show(true);
		}
		else
		widget.Show(false);
	}
}
