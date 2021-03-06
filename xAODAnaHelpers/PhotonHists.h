#ifndef xAODAnaHelpers_PhotonHists_H
#define xAODAnaHelpers_PhotonHists_H

#include "xAODAnaHelpers/IParticleHists.h"
#include <xAODEgamma/PhotonContainer.h>

#include <AthContainers/DataVector.h>

class PhotonHists : public IParticleHists
{
  public:


    PhotonHists(std::string name, std::string detailStr);
    virtual ~PhotonHists() ;

    virtual StatusCode initialize();
    virtual StatusCode execute( const xAOD::Photon* photon, float eventWeight, const xAOD::EventInfo* eventInfo = 0);
    using HistogramManager::book; // make other overloaded version of book() to show up in subclass
    using IParticleHists::execute; // overload

  protected:

    virtual StatusCode execute( const xAOD::IParticle* particle, float eventWeight, const xAOD::EventInfo* eventInfo = 0 );

    // holds bools that control which histograms are filled
    HelperClasses::PhotonInfoSwitch* m_infoSwitch;

  private:

    // clean
    TH1F* m_ptcone20;                //!
    TH1F* m_ptcone30;                //!
    TH1F* m_ptcone40;                //!
    TH1F* m_ptvarcone20;             //!
    TH1F* m_ptvarcone30;             //!
    TH1F* m_ptvarcone40;             //!
    TH1F* m_topoetcone20;            //!
    TH1F* m_topoetcone30;            //!
    TH1F* m_topoetcone40;            //!

};

#endif
