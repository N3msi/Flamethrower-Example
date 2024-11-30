
class nm_ScrapCanister_Mag extends MagazineStorage 
{
	override void SetActions()
	{
		super.SetActions();
		RemoveAction(ActionEmptyMagazine);
		AddAction(ActionnmRefuelnmCanisterFromPump);
	}
};

class nm_Ammo_Gasoline extends Ammunition_Base
{
	void nm_Ammo_Gasoline()
	{
		Delete();	//instantly delete after ejection
	}
	
	void ~nm_Ammo_Gasoline()
	{}
};


class nmFlamethrowerLight extends PointLightBase
{
	static float m_FTLRadius = 30;
	static float m_FTLBrightness = 5.0;
	float m_FadeOutDuration = 1.0;
	float m_CurrentTime = 0.0;

	void nmFlamethrowerLight() 
	{
		SetVisibleDuringDaylight(false);
		SetRadiusTo(m_FTLRadius);
		SetBrightnessTo(m_FTLBrightness);
		SetCastShadow(true);
		SetDiffuseColor(1.0, 0.45, 0.25);
		SetAmbientColor(1.0, 0.45, 0.25);
		SetFlareVisible(false);
		SetFlickerAmplitude(0.55);
		SetFlickerSpeed(0.75);
		SetDancingShadowsMovementSpeed(0.1);
		SetDancingShadowsAmplitude(0.03);
		EnableHeatHaze(true);
		SetHeatHazeRadius(0.08);
		SetHeatHazePower(0.015);
	}

	override void OnFrameLightSource(IEntity other, float timeSlice) {
		m_CurrentTime += timeSlice;
		if (m_CurrentTime <= m_FadeOutDuration) {
			float fadeProgress = m_CurrentTime / m_FadeOutDuration;
			float newBrightness = m_FTLBrightness * (1 - fadeProgress);
			SetBrightnessTo(newBrightness);
		}
	}
}

class nm_Flamethrower_Base extends RifleBoltFree_Base
{
    Particle m_nmFireParticle
    Particle m_nmSmokeParticle;
    Particle m_nmMuzzleParticle;
	nmFlamethrowerLight	 m_Light;
    const string SOUND_BURNING = "nm_FT_SoundSet";
	protected float m_LastEffectTime = 0;
    protected EffectSound m_SoundBurning;
    protected bool m_IsSoundPlaying;
	protected bool m_IsLightActive;

    override RecoilBase SpawnRecoilObject()
    {
        return null;
    }

	override float GetChanceToJam()
	{
		float chanceToJam = super.GetChanceToJam();
		
		chanceToJam = 0;
		
		return chanceToJam;		
	}	

	override string GetDestructionBehaviour()
    {
        return "DestructionEffectGasCanister";
    }

	override bool IsDestructionBehaviour()
	{
		if (CanEjectBullet())
		{
			return true;	// Blow up on ruined if loaded
		}

		return false;
	}
	
    bool IsSoundPlaying()
    {
        return m_IsSoundPlaying;
    }
	
	bool IsLightActive()
    {
        return m_IsLightActive;
    }

	override void EEFired(int muzzleType, int mode, string ammoType)
	{
		if (!GetGame().IsDedicatedServer())
		{
			// Sound effects
			if (!m_IsSoundPlaying)
			{
				SoundBurningStart();
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(SoundBurningStop, 1000, false);
			}

			// Light effects
			if (!m_IsLightActive) 
			{
				LightsStart();
				GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(LightsStop, 1000, false);
			}
				
			float currentTime = GetGame().GetTickTime();

			// play effects every 0.5 sec
			if (currentTime - m_LastEffectTime >= 0.5)
			{
				PlaynmEffects();
				m_LastEffectTime = currentTime;
			}
		}
	}

	void PlaynmEffects()
	{
		vector particlePos = GetMemoryPointPos("flame");  
		vector flameDirPos = GetMemoryPointPos("flame_dir");
		vector particleOrientation = vector.Direction(particlePos, flameDirPos); //calc vector

		// Fire particle
		m_nmFireParticle = Particle.PlayOnObject(ParticleList.NM_FLAMETHROWER, this, GetMemoryPointPos("flame"), particleOrientation, true);
		m_nmFireParticle.SetWiggle(3, 0.1);
		m_nmFireParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 2.0);

		// Smoke particle
		m_nmSmokeParticle = Particle.PlayOnObject(ParticleList.NM_SMOKE, this, GetMemoryPointPos("smoke"), particleOrientation, true);
		m_nmSmokeParticle.SetWiggle(3, 0.1);
		m_nmSmokeParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 0.5);

		// Muzzle particle
		m_nmMuzzleParticle = Particle.PlayOnObject(ParticleList.NM_MUZZLE, this, GetMemoryPointPos("muzzle"), particleOrientation, true);
		m_nmMuzzleParticle.SetWiggle(3, 0.1);
		m_nmMuzzleParticle.ScaleParticleParamFromOriginal(EmitorParam.SIZE, 1.0);


	}

    protected void LightsStart()
    {
		m_IsLightActive = true;
		m_Light = nmFlamethrowerLight.Cast(ScriptedLightBase.CreateLight(nmFlamethrowerLight, Vector(0, 0, 0), 1));
		m_Light.AttachOnMemoryPoint(this, "light");
		m_Light.SetFadeOutTime(1);
		m_Light.m_FTLRadius = 30;
		m_Light.Update();  
    }

	protected void LightsStop()
	{
		m_IsLightActive = false;
		if (m_Light)
			m_Light.FadeOut();
	}
	
    protected void SoundBurningStart()
    {
        m_IsSoundPlaying = true;
        PlaySoundSet(m_SoundBurning, SOUND_BURNING, 0.1, 0.0);
    }

    protected void SoundBurningStop()
    {
        m_IsSoundPlaying = false;
		if (m_SoundBurning)
		{
			m_SoundBurning.SoundStop();
		}
    }
	
	override void OnDebugSpawn()
	{
		GameInventory inventory = GetInventory();

		SpawnAttachedMagazine("nm_ScrapCanister_Mag");
	}	
}

class nm_Flamethrower extends nm_Flamethrower_Base{}

