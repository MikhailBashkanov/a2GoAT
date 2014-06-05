#include "GTreeParticle.h"
#include "GTreeManager.h"


using namespace std;


GTreeParticle::GTreeParticle(GTreeManager *Manager, const TString& _Name)    :
    GTree(Manager,_Name),
    nParticles(0),
    particles(new TClonesArray("TLorentzVector", 32))
{
    for(int i=0; i<GTreeParticle_MaxEntries; i++)
    {
        Apparatus[i]    = 0;
        time[i]         = 0;
        clusterSize[i]  = 0;
        d_E[i]          = 0;
        WC0_E[i]        = 0;
        WC1_E[i]        = 0;
    }
}

GTreeParticle::~GTreeParticle()
{
    if (particles)  delete particles;
}

void    GTreeParticle::SetBranchAdresses()
{
    tree_in->SetBranchAddress("nParticles",&nParticles);
    tree_in->SetBranchAddress("particles.", &particles);
    tree_in->SetBranchAddress("Apparatus",&Apparatus);
    tree_in->SetBranchAddress("time",&time);
    tree_in->SetBranchAddress("clusterSize",&clusterSize);
    tree_in->SetBranchAddress("d_E",&d_E);
    tree_in->SetBranchAddress("WC0_E",&WC0_E);
    tree_in->SetBranchAddress("WC1_E",&WC1_E);
}

void    GTreeParticle::SetBranches()
{
    tree_out->Branch("nParticles",&nParticles, "nParticles/i");
    tree_out->Branch("particles.", &particles, 32000, 0);
    tree_out->Branch("Apparatus",&Apparatus, "Apparatus[nParticles]/b");
    tree_out->Branch("time",&time, "time[nParticles]/D");
    tree_out->Branch("clusterSize",&clusterSize, "clusterSize[nParticles]/b");
    tree_out->Branch("d_E",&d_E, "d_E[nParticles]/D");
    tree_out->Branch("WC0_E",&WC0_E, "WC0_E[nParticles]/D");
    tree_out->Branch("WC1_E",&WC1_E, "WC1_E[nParticles]/D");
}
