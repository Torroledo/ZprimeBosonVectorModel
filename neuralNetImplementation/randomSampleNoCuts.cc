#include <iostream>
#include <algorithm>
#include <time.h>
#include <random>
extern const string back1="W+jets.root";  
extern const string back2="DY+jets.root";  

void selectJets(std::string inFolder, std::string outFolder, std::string signal){

void randomSampleNoCtus(){

  // 1. Load each Tree individually 
  std::string inFolder = "fullSample/";
  std::string outFolder = "randomSample/";

  std::string signal2 = "signal_0p5TeV.root";
  std::string signal3 = "signal_1p0TeV.root";
  std::string signal4 = "signal_1p25TeV.root";
  std::string signal5 = "signal_2p0TeV.root";
  //std::string back2 = "W+jets.root";
  //std::string back1 = "DY+jets.root";

  selectRandom(inFolder, outFolder, signal2);
  
  // 2. Merge Data
  merge(signal2);
  /*
  TChain * chain = new TChain("totalSimulation");
  chain->Add((outFolder+signal2).c_str());
  chain->Add((outFolder+signal3).c_str());
  chain->Add((outFolder+signal4).c_str());
  chain->Add((outFolder+signal5).c_str());
  chain->Add((outFolder+back1).c_str());
  chain->Add((outFolder+back2).c_str());

  chain->Merge((outFolder+finalFile).c_str());
  cout << "total entries :" << chain->GetEntries() << endl;
  */
}
 
void selectRandom(std::string inFolder, std::string outFolder, std::string signal){
  
  // Loading signal data from .root file                                             
  TFile* signalFile1 = new TFile((inFolder + filename).c_str());
  TTree* treeSignal = (TTree *) signalFile1->Get("totalSimulation");
  TFile* backFile1 = new TFile((inFolder + back1).c_str());
  TTree* treeBack1 = (TTree *) backFile1->Get("totalSimulation");  
  TFile* backFile2 = new TFile((inFolder + back2).c_str());
  TTree* treeBack2 = (TTree *) backFile2->Get("totalSimulation");

  // Creating a final marged TTree
  TFile* finalData = new TFile((outFolder + filename).c_str(),"RECREATE"); 
  TTree* totalSimulation = new TTree("totalSimulation","Joined Normalized Data");  
  
  // INPUT VARIABLES && OUTPUT VARIABLES
  // Declaring TAUS variables
  Int_t Tau_Charge, Tau_Charge_1, Tau_Charge_2;
  Float_t Tau_PT_sum, Tau_PT_dif, Tau_PT_1, Tau_PT_2;
  Float_t Tau_Mass_sum, Tau_Mass_dif, Tau_Mass_1, Tau_Mass_2;
  Float_t Tau_Ener_sum, Tau_Ener_1, Tau_Ener_2;
  Float_t Tau_Eta_dif, Tau_Eta_1, Tau_Eta_2;
  Float_t Tau_Phi_dif, Tau_Phi_1, Tau_Phi_2;
  Float_t Tau_DeltaEta, Tau_DeltaPhi;
  Float_t Tau_EhadOverEem;

  // Declaring TAGGING variables
  Int_t BTag,TauTag;

  // Declaring MISS ET variables 
  Float_t Miss_MET, Miss_Eta, Miss_Phi;

  // Declaring output variables JETS
  Int_t Jet_Charge, Jet_Charge_1, Jet_Charge_2;
  Float_t Jet_PT_sum, Jet_PT_dif, Jet_PT_1, Jet_PT_2;
  Float_t Jet_Mass_sum, Jet_Mass_dif, Jet_Mass_1, Jet_Mass_2;
  Float_t Jet_Ener_sum, Jet_Ener_1, Jet_Ener_2;
  Float_t Jet_Eta_dif, Jet_Eta_1, Jet_Eta_2;
  Float_t Jet_Phi_dif, Jet_Phi_1, Jet_Phi_2; 
  Float_t Jet_DeltaEta, Jet_DeltaPhi;
  Float_t Jet_T_1, Jet_T_2, Jet_BetaStar_1, Jet_BetaStar_2;
  Float_t Jet_EhadOverEem_1, Jet_EhadOverEem_2;
  Float_t Jet_MeanSqDeltaR_1, Jet_MeanSqDeltaR_2;
  Float_t Jet_PTD_1, Jet_PTD_2, Jet_Beta_1,Jet_Beta_2;

  treeSignal->SetBranchAddress("type", &type);
  treeSignal->SetBranchAddress("type_2", &type_2);
  treeSignal->SetBranchAddress("Tau_PT_sum",  &Tau_PT_sum);
  treeSignal->SetBranchAddress("Tau_PT_dif",  &Tau_PT_dif);
  treeSignal->SetBranchAddress("Tau_PT_1",  &Tau_PT_1);
  treeSignal->SetBranchAddress("Tau_PT_2",  &Tau_PT_2);
  treeSignal->SetBranchAddress("Tau_Eta_dif",  &Tau_Eta_dif);
  treeSignal->SetBranchAddress("Tau_Eta_1",  &Tau_Eta_1);
  treeSignal->SetBranchAddress("Tau_Eta_2",  &Tau_Eta_2);
  treeSignal->SetBranchAddress("Tau_Phi_dif",  &Tau_Phi_dif);
  treeSignal->SetBranchAddress("Tau_Phi_1",  &Tau_Phi_1);
  treeSignal->SetBranchAddress("Tau_Phi_2",  &Tau_Phi_2);
  treeSignal->SetBranchAddress("Tau_DeltaEta",  &Tau_DeltaEta);
  treeSignal->SetBranchAddress("Tau_DeltaPhi",  &Tau_DeltaPhi);
  treeSignal->SetBranchAddress("Tau_Charge_1",  &Tau_Charge_1);
  treeSignal->SetBranchAddress("Tau_Charge_2",  &Tau_Charge_2);
  treeSignal->SetBranchAddress("Tau_Mass_sum",  &Tau_Mass_sum);
  treeSignal->SetBranchAddress("Tau_Mass_dif",  &Tau_Mass_dif);
  treeSignal->SetBranchAddress("Tau_Mass_1",  &Tau_Mass_1);
  treeSignal->SetBranchAddress("Tau_Mass_2",  &Tau_Mass_2);
  treeSignal->SetBranchAddress("TauTag",  &TauTag);
  treeSignal->SetBranchAddress("Tau_Ener_sum",  &Tau_Ener_sum);
  treeSignal->SetBranchAddress("Tau_Ener_1",  &Tau_Ener_1);  
  treeSignal->SetBranchAddress("Tau_Ener_2",  &Tau_Ener_2);

  treeSignal->SetBranchAddress("Miss_MET",  &Miss_MET);                            
  treeSignal->SetBranchAddress("Miss_Eta",  &Miss_Eta);                           
  treeSignal->SetBranchAddress("Miss_Phi",  &Miss_Phi);                           
  
  treeSignal->SetBranchAddress("Jet_PT_sum",   &Jet_PT_sum);
  treeSignal->SetBranchAddress("Jet_PT_dif",   &Jet_PT_dif);
  treeSignal->SetBranchAddress("Jet_PT_1",   &Jet_PT_1);
  treeSignal->SetBranchAddress("Jet_PT_2",   &Jet_PT_2);
  treeSignal->SetBranchAddress("Jet_Mass_sum", &Jet_Mass_sum); 
  treeSignal->SetBranchAddress("Jet_Mass_dif", &Jet_Mass_dif);
  treeSignal->SetBranchAddress("Jet_Mass_1", &Jet_Mass_1);
  treeSignal->SetBranchAddress("Jet_Mass_2",&Jet_Mass_2);
  treeSignal->SetBranchAddress("Jet_Eta_dif",  &Jet_Eta_dif);
  treeSignal->SetBranchAddress("Jet_Eta_1",  &Jet_Eta_1);
  treeSignal->SetBranchAddress("Jet_Eta_2",  &Jet_Eta_2);
  treeSignal->SetBranchAddress("Jet_Phi_dif",  &Jet_Phi_dif);
  treeSignal->SetBranchAddress("Jet_Phi_1",  &Jet_Phi_1);
  treeSignal->SetBranchAddress("Jet_Phi_2",  &Jet_Phi_2);
  treeSignal->SetBranchAddress("Jet_DeltaEta",    &Jet_DeltaEta);
  treeSignal->SetBranchAddress("Jet_DeltaPhi",    &Jet_DeltaPhi);
  treeSignal->SetBranchAddress("Jet_T_1",    &Jet_T_1);                           
  treeSignal->SetBranchAddress("Jet_T_2",    &Jet_T_2);
  treeSignal->SetBranchAddress("Jet_Charge_1",  &Jet_Charge_1);
  treeSignal->SetBranchAddress("Jet_Charge_2",  &Jet_Charge_2);
  treeSignal->SetBranchAddress("Jet_EhadOverEem_1", &Jet_EhadOverEem_1);
  treeSignal->SetBranchAddress("Jet_EhadOverEem_2", &Jet_EhadOverEem_2);
  treeSignal->SetBranchAddress("Jet_Ener_sum", &Jet_Ener_sum);
  treeSignal->SetBranchAddress("Jet_Ener_1", &Jet_Ener_1);
  treeSignal->SetBranchAddress("Jet_Ener_2",&Jet_Ener_2);
  treeSignal->SetBranchAddress("BTag", &BTag);


  treeBack1->SetBranchAddress("type", &type);
  treeBack1->SetBranchAddress("type_2", &type_2);
  treeBack1->SetBranchAddress("Tau_PT_sum",  &Tau_PT_sum);
  treeBack1->SetBranchAddress("Tau_PT_dif",  &Tau_PT_dif);
  treeBack1->SetBranchAddress("Tau_PT_1",  &Tau_PT_1);
  treeBack1->SetBranchAddress("Tau_PT_2",  &Tau_PT_2);
  treeBack1->SetBranchAddress("Tau_Eta_dif",  &Tau_Eta_dif);
  treeBack1->SetBranchAddress("Tau_Eta_1",  &Tau_Eta_1);
  treeBack1->SetBranchAddress("Tau_Eta_2",  &Tau_Eta_2);
  treeBack1->SetBranchAddress("Tau_Phi_dif",  &Tau_Phi_dif);
  treeBack1->SetBranchAddress("Tau_Phi_1",  &Tau_Phi_1);
  treeBack1->SetBranchAddress("Tau_Phi_2",  &Tau_Phi_2);
  treeBack1->SetBranchAddress("Tau_DeltaEta",  &Tau_DeltaEta);
  treeBack1->SetBranchAddress("Tau_DeltaPhi",  &Tau_DeltaPhi);
  treeBack1->SetBranchAddress("Tau_Charge_1",  &Tau_Charge_1);
  treeBack1->SetBranchAddress("Tau_Charge_2",  &Tau_Charge_2);
  treeBack1->SetBranchAddress("Tau_Mass_sum",  &Tau_Mass_sum);
  treeBack1->SetBranchAddress("Tau_Mass_dif",  &Tau_Mass_dif);
  treeBack1->SetBranchAddress("Tau_Mass_1",  &Tau_Mass_1);
  treeBack1->SetBranchAddress("Tau_Mass_2",  &Tau_Mass_2);
  treeBack1->SetBranchAddress("TauTag",  &TauTag);
  treeBack1->SetBranchAddress("Tau_Ener_sum",  &Tau_Ener_sum);
  treeBack1->SetBranchAddress("Tau_Ener_1",  &Tau_Ener_1);  
  treeBack1->SetBranchAddress("Tau_Ener_2",  &Tau_Ener_2);

  treeBack1->SetBranchAddress("Miss_MET",  &Miss_MET);                            
  treeBack1->SetBranchAddress("Miss_Eta",  &Miss_Eta);                           
  treeBack1->SetBranchAddress("Miss_Phi",  &Miss_Phi);                           
  
  treeBack1->SetBranchAddress("Jet_PT_sum",   &Jet_PT_sum);
  treeBack1->SetBranchAddress("Jet_PT_dif",   &Jet_PT_dif);
  treeBack1->SetBranchAddress("Jet_PT_1",   &Jet_PT_1);
  treeBack1->SetBranchAddress("Jet_PT_2",   &Jet_PT_2);
  treeBack1->SetBranchAddress("Jet_Mass_sum", &Jet_Mass_sum); 
  treeBack1->SetBranchAddress("Jet_Mass_dif", &Jet_Mass_dif);
  treeBack1->SetBranchAddress("Jet_Mass_1", &Jet_Mass_1);
  treeBack1->SetBranchAddress("Jet_Mass_2",&Jet_Mass_2);
  treeBack1->SetBranchAddress("Jet_Eta_dif",  &Jet_Eta_dif);
  treeBack1->SetBranchAddress("Jet_Eta_1",  &Jet_Eta_1);
  treeBack1->SetBranchAddress("Jet_Eta_2",  &Jet_Eta_2);
  treeBack1->SetBranchAddress("Jet_Phi_dif",  &Jet_Phi_dif);
  treeBack1->SetBranchAddress("Jet_Phi_1",  &Jet_Phi_1);
  treeBack1->SetBranchAddress("Jet_Phi_2",  &Jet_Phi_2);
  treeBack1->SetBranchAddress("Jet_DeltaEta",    &Jet_DeltaEta);
  treeBack1->SetBranchAddress("Jet_DeltaPhi",    &Jet_DeltaPhi);
  treeBack1->SetBranchAddress("Jet_T_1",    &Jet_T_1);                           
  treeBack1->SetBranchAddress("Jet_T_2",    &Jet_T_2);
  treeBack1->SetBranchAddress("Jet_Charge_1",  &Jet_Charge_1);
  treeBack1->SetBranchAddress("Jet_Charge_2",  &Jet_Charge_2);
  treeBack1->SetBranchAddress("Jet_EhadOverEem_1", &Jet_EhadOverEem_1);
  treeBack1->SetBranchAddress("Jet_EhadOverEem_2", &Jet_EhadOverEem_2);
  treeBack1->SetBranchAddress("Jet_Ener_sum", &Jet_Ener_sum);
  treeBack1->SetBranchAddress("Jet_Ener_1", &Jet_Ener_1);
  treeBack1->SetBranchAddress("Jet_Ener_2",&Jet_Ener_2);
  treeBack1->SetBranchAddress("BTag", &BTag);



  treeBack2->SetBranchAddress("type", &type);
  treeBack2->SetBranchAddress("type_2", &type_2);
  treeBack2->SetBranchAddress("Tau_PT_sum",  &Tau_PT_sum);
  treeBack2->SetBranchAddress("Tau_PT_dif",  &Tau_PT_dif);
  treeBack2->SetBranchAddress("Tau_PT_1",  &Tau_PT_1);
  treeBack2->SetBranchAddress("Tau_PT_2",  &Tau_PT_2);
  treeBack2->SetBranchAddress("Tau_Eta_dif",  &Tau_Eta_dif);
  treeBack2->SetBranchAddress("Tau_Eta_1",  &Tau_Eta_1);
  treeBack2->SetBranchAddress("Tau_Eta_2",  &Tau_Eta_2);
  treeBack2->SetBranchAddress("Tau_Phi_dif",  &Tau_Phi_dif);
  treeBack2->SetBranchAddress("Tau_Phi_1",  &Tau_Phi_1);
  treeBack2->SetBranchAddress("Tau_Phi_2",  &Tau_Phi_2);
  treeBack2->SetBranchAddress("Tau_DeltaEta",  &Tau_DeltaEta);
  treeBack2->SetBranchAddress("Tau_DeltaPhi",  &Tau_DeltaPhi);
  treeBack2->SetBranchAddress("Tau_Charge_1",  &Tau_Charge_1);
  treeBack2->SetBranchAddress("Tau_Charge_2",  &Tau_Charge_2);
  treeBack2->SetBranchAddress("Tau_Mass_sum",  &Tau_Mass_sum);
  treeBack2->SetBranchAddress("Tau_Mass_dif",  &Tau_Mass_dif);
  treeBack2->SetBranchAddress("Tau_Mass_1",  &Tau_Mass_1);
  treeBack2->SetBranchAddress("Tau_Mass_2",  &Tau_Mass_2);
  treeBack2->SetBranchAddress("TauTag",  &TauTag);
  treeBack2->SetBranchAddress("Tau_Ener_sum",  &Tau_Ener_sum);
  treeBack2->SetBranchAddress("Tau_Ener_1",  &Tau_Ener_1);  
  treeBack2->SetBranchAddress("Tau_Ener_2",  &Tau_Ener_2);

  treeBack2->SetBranchAddress("Miss_MET",  &Miss_MET);                            
  treeBack2->SetBranchAddress("Miss_Eta",  &Miss_Eta);                           
  treeBack2->SetBranchAddress("Miss_Phi",  &Miss_Phi);                           
  
  treeBack2->SetBranchAddress("Jet_PT_sum",   &Jet_PT_sum);
  treeBack2->SetBranchAddress("Jet_PT_dif",   &Jet_PT_dif);
  treeBack2->SetBranchAddress("Jet_PT_1",   &Jet_PT_1);
  treeBack2->SetBranchAddress("Jet_PT_2",   &Jet_PT_2);
  treeBack2->SetBranchAddress("Jet_Mass_sum", &Jet_Mass_sum); 
  treeBack2->SetBranchAddress("Jet_Mass_dif", &Jet_Mass_dif);
  treeBack2->SetBranchAddress("Jet_Mass_1", &Jet_Mass_1);
  treeBack2->SetBranchAddress("Jet_Mass_2",&Jet_Mass_2);
  treeBack2->SetBranchAddress("Jet_Eta_dif",  &Jet_Eta_dif);
  treeBack2->SetBranchAddress("Jet_Eta_1",  &Jet_Eta_1);
  treeBack2->SetBranchAddress("Jet_Eta_2",  &Jet_Eta_2);
  treeBack2->SetBranchAddress("Jet_Phi_dif",  &Jet_Phi_dif);
  treeBack2->SetBranchAddress("Jet_Phi_1",  &Jet_Phi_1);
  treeBack2->SetBranchAddress("Jet_Phi_2",  &Jet_Phi_2);
  treeBack2->SetBranchAddress("Jet_DeltaEta",    &Jet_DeltaEta);
  treeBack2->SetBranchAddress("Jet_DeltaPhi",    &Jet_DeltaPhi);
  treeBack2->SetBranchAddress("Jet_T_1",    &Jet_T_1);                           
  treeBack2->SetBranchAddress("Jet_T_2",    &Jet_T_2);
  treeBack2->SetBranchAddress("Jet_Charge_1",  &Jet_Charge_1);
  treeBack2->SetBranchAddress("Jet_Charge_2",  &Jet_Charge_2);
  treeBack2->SetBranchAddress("Jet_EhadOverEem_1", &Jet_EhadOverEem_1);
  treeBack2->SetBranchAddress("Jet_EhadOverEem_2", &Jet_EhadOverEem_2);
  treeBack2->SetBranchAddress("Jet_Ener_sum", &Jet_Ener_sum);
  treeBack2->SetBranchAddress("Jet_Ener_1", &Jet_Ener_1);
  treeBack2->SetBranchAddress("Jet_Ener_2",&Jet_Ener_2);
  treeBack2->SetBranchAddress("BTag", &BTag);



  
  totalSimulation->Branch("type", &type);
  totalSimulation->Branch("type_2", &type_2);
  totalSimulation->Branch("Tau_PT_sum",  &Tau_PT_sum);
  totalSimulation->Branch("Tau_PT_dif",  &Tau_PT_dif);
  totalSimulation->Branch("Tau_PT_1",  &Tau_PT_1);
  totalSimulation->Branch("Tau_PT_2",  &Tau_PT_2);
  totalSimulation->Branch("Tau_Eta_dif",  &Tau_Eta_dif);
  totalSimulation->Branch("Tau_Eta_1",  &Tau_Eta_1);
  totalSimulation->Branch("Tau_Eta_2",  &Tau_Eta_2);
  totalSimulation->Branch("Tau_Phi_dif",  &Tau_Phi_dif);
  totalSimulation->Branch("Tau_Phi_1",  &Tau_Phi_1);
  totalSimulation->Branch("Tau_Phi_2",  &Tau_Phi_2);
  totalSimulation->Branch("Tau_DeltaEta",  &Tau_DeltaEta);
  totalSimulation->Branch("Tau_DeltaPhi",  &Tau_DeltaPhi);
  totalSimulation->Branch("Tau_Charge_1",  &Tau_Charge_1);
  totalSimulation->Branch("Tau_Charge_2",  &Tau_Charge_2);
  totalSimulation->Branch("Tau_Mass_sum",  &Tau_Mass_sum);
  totalSimulation->Branch("Tau_Mass_dif",  &Tau_Mass_dif);
  totalSimulation->Branch("Tau_Mass_1",  &Tau_Mass_1);
  totalSimulation->Branch("Tau_Mass_2",  &Tau_Mass_2);
  totalSimulation->Branch("TauTag",  &TauTag);
  totalSimulation->Branch("Tau_Ener_sum",  &Tau_Ener_sum);
  totalSimulation->Branch("Tau_Ener_1",  &Tau_Ener_1);  
  totalSimulation->Branch("Tau_Ener_2",  &Tau_Ener_2);

  totalSimulation->Branch("Miss_MET",  &Miss_MET);                            
  totalSimulation->Branch("Miss_Eta",  &Miss_Eta);                           
  totalSimulation->Branch("Miss_Phi",  &Miss_Phi);                           
  
  totalSimulation->Branch("Jet_PT_sum",   &Jet_PT_sum);
  totalSimulation->Branch("Jet_PT_dif",   &Jet_PT_dif);
  totalSimulation->Branch("Jet_PT_1",   &Jet_PT_1);
  totalSimulation->Branch("Jet_PT_2",   &Jet_PT_2);
  totalSimulation->Branch("Jet_Mass_sum", &Jet_Mass_sum); 
  totalSimulation->Branch("Jet_Mass_dif", &Jet_Mass_dif);
  totalSimulation->Branch("Jet_Mass_1", &Jet_Mass_1);
  totalSimulation->Branch("Jet_Mass_2",&Jet_Mass_2);
  totalSimulation->Branch("Jet_Eta_dif",  &Jet_Eta_dif);
  totalSimulation->Branch("Jet_Eta_1",  &Jet_Eta_1);
  totalSimulation->Branch("Jet_Eta_2",  &Jet_Eta_2);
  totalSimulation->Branch("Jet_Phi_dif",  &Jet_Phi_dif);
  totalSimulation->Branch("Jet_Phi_1",  &Jet_Phi_1);
  totalSimulation->Branch("Jet_Phi_2",  &Jet_Phi_2);
  totalSimulation->Branch("Jet_DeltaEta",    &Jet_DeltaEta);
  totalSimulation->Branch("Jet_DeltaPhi",    &Jet_DeltaPhi);
  totalSimulation->Branch("Jet_T_1",    &Jet_T_1);                           
  totalSimulation->Branch("Jet_T_2",    &Jet_T_2);
  totalSimulation->Branch("Jet_Charge_1",  &Jet_Charge_1);
  totalSimulation->Branch("Jet_Charge_2",  &Jet_Charge_2);
  totalSimulation->Branch("Jet_EhadOverEem_1", &Jet_EhadOverEem_1);
  totalSimulation->Branch("Jet_EhadOverEem_2", &Jet_EhadOverEem_2);
  totalSimulation->Branch("Jet_Ener_sum", &Jet_Ener_sum);
  totalSimulation->Branch("Jet_Ener_1", &Jet_Ener_1);
  totalSimulation->Branch("Jet_Ener_2",&Jet_Ener_2);
  totalSimulation->Branch("BTag", &BTag);
 
  // Initializing indexing variables
  std::vector<int> Tau_index,Jet_index;
  Tau_index.push_back(-1); Tau_index.push_back(-1);
  Jet_index.push_back(-1); Jet_index.push_back(-1);

  // Number of variables
  int numberOfEntries = treeSignal->GetEntries();
  cout << "Tree " << filename << " has : " << numberOfEntries << " entries" << endl;
  cout << "type " << type << endl;

  // ------------------- set the random entries to select ------------------
  int i = 0; 
  while(i<numberOfEntries) {
    Int_t j = rand.Uniform(0,numberOfEntries);
    cout << j << endl;
    /*if (bits->TestBitNumber(j)) continue;  //we have already seen this entry
      bits->SetBitNumber(j);*/
    i++;
  }

  // ------------------- set the random entries to select ------------------ 
  for (int entry = 0; entry < numberOfEntries; ++entry){
    treeSignal->GetEntry(entry);        
    
    if (J_TauTag->size()>3){ 

      Tau_index.at(0)=-1;
      Tau_index.at(1)=-1;
      Jet_index.at(0)=-1;
      Jet_index.at(1)=-1;
      
      get_allowed_taus(Tau_index,J_TauTag,J_PT,J_Eta,J_Phi,J_Charge); 
      get_allowed_jets(Jet_index,J_TauTag,J_PT,J_Eta,J_Phi,J_Charge,J_BTag);
      
      if (Tau_index.at(0)>=0 && Jet_index.at(0)>=0 && Tau_index.at(1)>=0 && Jet_index.at(1)>=0){
	
	leading_PT(Tau_index,J_PT);
	leading_PT(Jet_index,J_PT);
	
	// MISSING ET selection                                                                     
	if (M_MET->size()>1){
	  cout << "There shouldn't be more than one MissET " << M_MET->size() << endl;
	}
	Miss_MET = M_MET->at(0);
	Miss_Eta = M_Eta->at(0);
	Miss_Phi = M_Phi->at(0);
	
	// TAUS SELECTION	  
	Tau_PT_sum = (J_PT->at(Tau_index.at(0)) + J_PT->at(Tau_index.at(1))) ;
	Tau_PT_dif = (J_PT->at(Tau_index.at(0)) - J_PT->at(Tau_index.at(1))) ;
	Tau_PT_1 = J_PT->at(Tau_index.at(0)) ;
	Tau_PT_2 = J_PT->at(Tau_index.at(1)) ;
	Tau_Mass_sum = (J_Mass->at(Tau_index.at(0)) + J_Mass->at(Tau_index.at(1))) ;
	Tau_Mass_dif = (J_Mass->at(Tau_index.at(0)) - J_Mass->at(Tau_index.at(1))) ;
	Tau_Mass_1 = J_Mass->at(Tau_index.at(0)) ;
	Tau_Mass_2 = J_Mass->at(Tau_index.at(1)) ;
	Tau_Eta_dif = J_Eta->at(Tau_index.at(0)) - J_Eta->at(Tau_index.at(1)) ;
	Tau_Eta_1 = J_Eta->at(Tau_index.at(0)) ;
	Tau_Eta_2 = J_Eta->at(Tau_index.at(1)) ;
	Tau_Phi_dif = (J_Phi->at(Tau_index.at(0)) - J_Phi->at(Tau_index.at(1))) ;
	Tau_Phi_1 = (J_Phi->at(Tau_index.at(0))) ;
	Tau_Phi_2 = (J_Phi->at(Tau_index.at(1))) ;
	Tau_DeltaEta = max(J_DeltaEta->at(Tau_index.at(0)),J_DeltaEta->at(Tau_index.at(1))) ;
	Tau_DeltaPhi = max(J_DeltaPhi->at(Tau_index.at(0)),J_DeltaPhi->at(Tau_index.at(1))) ;
	Tau_Charge_1 = (J_Charge->at(Tau_index.at(0)));
	Tau_Charge_2 = (J_Charge->at(Tau_index.at(1)));
	Tau_Ener_1 = calculateE(J_Eta->at(Tau_index.at(0)),J_PT->at(Tau_index.at(0)),J_Mass->at(Tau_index.at(0)));
	Tau_Ener_2 = calculateE(J_Eta->at(Tau_index.at(1)),J_PT->at(Tau_index.at(1)),J_Mass->at(Tau_index.at(1)));
	Tau_Ener_sum = Tau_Ener_1 + Tau_Ener_2;
	TauTag = J_TauTag->at(Tau_index.at(0)) * J_TauTag->at(Tau_index.at(1));
	  
	// JETS SELECTION
	Jet_PT_sum = (J_PT->at(Jet_index.at(0)) + J_PT->at(Jet_index.at(1))) ;	
	Jet_PT_dif = (J_PT->at(Jet_index.at(0)) - J_PT->at(Jet_index.at(1))) ;
	Jet_PT_1 = J_PT->at(Jet_index.at(0)) ;
	Jet_PT_2 = J_PT->at(Jet_index.at(1)) ;
	Jet_Mass_sum = (J_Mass->at(Jet_index.at(0)) + J_Mass->at(Jet_index.at(1))) ;
	Jet_Mass_dif = (J_Mass->at(Jet_index.at(0)) - J_Mass->at(Jet_index.at(1))) ;
	Jet_Mass_1 = J_Mass->at(Jet_index.at(0)) ;
	Jet_Mass_2 = J_Mass->at(Jet_index.at(1)) ;
	Jet_Eta_dif = J_Eta->at(Jet_index.at(0)) - J_Eta->at(Jet_index.at(1)) ;
	Jet_Eta_1 = J_Eta->at(Jet_index.at(0)) ;
	Jet_Eta_2 = J_Eta->at(Jet_index.at(1)) ;
	Jet_Phi_dif = (J_Phi->at(Jet_index.at(0)) - J_Phi->at(Jet_index.at(1))) ;
	Jet_Phi_1 = (J_Phi->at(Jet_index.at(0))) ;
	Jet_Phi_2 = (J_Phi->at(Jet_index.at(1))) ;
	Jet_DeltaEta = max(J_DeltaEta->at(Jet_index.at(0)),J_DeltaEta->at(Jet_index.at(1))) ;
	Tau_DeltaPhi = max(J_DeltaPhi->at(Jet_index.at(0)),J_DeltaPhi->at(Jet_index.at(1))) ;
	Jet_T_1 = (J_T->at(Jet_index.at(0))) ;
	Jet_T_2 = (J_T->at(Jet_index.at(1))) ;
	Jet_Charge_1 = (J_Charge->at(Jet_index.at(0)));
	Jet_Charge_2 = (J_Charge->at(Jet_index.at(1)));
	Jet_EhadOverEem_1 = (J_EhadOverEem->at(Jet_index.at(0))) ;
	Jet_EhadOverEem_2 = (J_EhadOverEem->at(Jet_index.at(1))) ;
	Jet_Ener_1 = calculateE(J_Eta->at(Jet_index.at(0)),J_PT->at(Jet_index.at(0)),J_Mass->at(Jet_index.at(0)));
	Jet_Ener_2 = calculateE(J_Eta->at(Jet_index.at(1)),J_PT->at(Jet_index.at(1)),J_Mass->at(Jet_index.at(1)));
	Jet_Ener_sum = Jet_Ener_1 + Jet_Ener_2;
	BTag = J_BTag->at(Jet_index.at(0)) + J_BTag->at(Jet_index.at(1)); 
	
	totalSimulation->Fill();
      }
    }
    if(!(entry%5000000)){
      cout << "Entry : "<< entry << endl;
    } 
  }
  cout << totalSimulation->GetEntries() << " gotten entries " << endl;
  finalData->Write();
  finalData->Close();
}

int find_position(std::vector<Float_t> array,Float_t value){
  int position=-1;
  for (int i=0;i<array.size();i++){
    if(array.at(i)==value){
      position=i;
      break;
    }
  }
  return position;
}

void get_allowed_taus(std::vector<int>& index,std::vector<UInt_t> * J_TauTag,std::vector<Float_t>* J_PT,std::vector<Float_t> * J_Eta,std::vector<Float_t>* J_Phi, std::vector<Int_t> * J_Charge){  
  
  std::vector<int> pos, neg;
  std::vector<Float_t> sel_PT_pos,sel_PT_pos_sorted,sel_PT_neg,sel_PT_neg_sorted;
  
  for(int tau_i = 0; tau_i < J_TauTag->size(); tau_i++){
    if(J_TauTag->at(tau_i)==1){
      if(J_Charge->at(tau_i)>0){
	pos.push_back(tau_i);
      }
      else{
	neg.push_back(tau_i);
      }
    }
  } 

  // POS
  if(pos.size()>0){
    if(pos.size()==1){
      index.at(0)=pos.at(0);
    }
    else{
      for(int sel = 0 ; sel < pos.size(); sel ++){
        sel_PT_pos.push_back(J_PT->at(pos.at(sel)));
      }
      sel_PT_pos_sorted = sel_PT_pos;
      std::sort(sel_PT_pos_sorted.begin(),sel_PT_pos_sorted.end());
      index.at(0) = pos.at(find_position(sel_PT_pos,sel_PT_pos_sorted.at(sel_PT_pos_sorted.size()-1)));
    }
  }

  // NEG
  if(neg.size()>0){
    if(neg.size()==1){
      index.at(1) = neg.at(0);
    }
    else{
      for(int sel = 0 ; sel < neg.size(); sel ++){
        sel_PT_neg.push_back(J_PT->at(neg.at(sel)));
      }
      sel_PT_neg_sorted = sel_PT_neg;
      std::sort(sel_PT_neg_sorted.begin(),sel_PT_neg_sorted.end());
      index.at(1) = neg.at(find_position(sel_PT_neg,sel_PT_neg_sorted.at(sel_PT_neg_sorted.size()-1)));
    }
  }
}

void get_allowed_jets(std::vector<int>& index, std::vector<UInt_t>* J_TauTag,std::vector<Float_t> *J_PT, std::vector<Float_t>* J_Eta, std::vector<Float_t>* J_Phi, std::vector<Int_t> * J_Charge, std::vector<UInt_t> *J_BTag){
  
  std::vector<int> pos, neg;
  std::vector<Float_t> sel_PT_pos,sel_PT_pos_sorted, sel_PT_neg, sel_PT_neg_sorted;

  for(int jet_i = 0; jet_i < J_TauTag->size(); jet_i++){
    if(J_TauTag->at(jet_i)==0){
      if(J_BTag->at(jet_i)==0){
	if(J_Eta->at(jet_i)>=0){
	  //cout << "++ " << jet_i << ". positive Eta: " << J_Eta->at(jet_i) <<" PT: " << J_PT->at(jet_i) << " Charge: " << J_Charge->at(jet_i) << endl;
	  pos.push_back(jet_i);
	}
	else{
	  //cout << "-- " << jet_i << ". negative Eta: " << J_Eta->at(jet_i) <<" PT: " << J_PT->at(jet_i) << " Charge: " << J_Charge->at(jet_i) << endl;
	  neg.push_back(jet_i);
	}
      }
      else{ 
	//cout << " BTAG = 1 -  "<< jet_i << ".  Non desiered Backgorund Btag " << " Charge: " << J_Charge->at(jet_i) << endl;
      } 
    }
    else{
      //      cout << "TAUTAG = 1 " << jet_i << ". possible taus : " << J_Eta->at(jet_i) <<" PT: " << J_PT->at(jet_i) << " Charge: " << J_Charge->at(jet_i) << endl;
    }
  }

  // get max pos
  if(pos.size()>0){
    if(pos.size()==1){
      index.at(0) = pos.at(0);
      // cout << " just one positive vale"<< endl;
    }
    else{
      for(int sel = 0 ; sel < pos.size(); sel ++){
	sel_PT_pos.push_back(J_PT->at(pos.at(sel)));
      }
      sel_PT_pos_sorted = sel_PT_pos;
      std::sort(sel_PT_pos_sorted.begin(),sel_PT_pos_sorted.end());
      index.at(0) = pos.at(find_position(sel_PT_pos,sel_PT_pos_sorted.at(sel_PT_pos_sorted.size()-1)));
    }
  }
  
  // get max neg 
  if(neg.size()>0){
    if(neg.size()==1){
      index.at(1) = neg.at(0);
      //      cout << " just one negative vale" << endl;
    }
    else{
      for(int sel = 0 ; sel < neg.size(); sel ++){
	sel_PT_neg.push_back(J_PT->at(neg.at(sel)));
      }
      sel_PT_neg_sorted = sel_PT_neg;
      std::sort(sel_PT_neg_sorted.begin(),sel_PT_neg_sorted.end());
      index.at(1) = neg.at(find_position(sel_PT_neg,sel_PT_neg_sorted.at(sel_PT_neg_sorted.size()-1)));
    }
  }
  /*
  if(index.at(0)>=0){
    cout << "     Max positive value:  " << J_PT->at(index.at(0)) << endl;
  }
  else{
    cout << "???? there is not max positive value " << endl;
  }

  if(index.at(1)>=0){
    cout << "     Max negative value:  " << J_PT->at(index.at(1)) << endl;  
  }
  else{
    cout << "???? there is not max negative value " << endl;
  }
  cout << "pos size: " << pos.size() << " neg size: " << neg.size() << endl;  
  */
}

void leading_PT(std::vector<int>& index,std::vector<Float_t> *J_PT){

  if(J_PT->at(index.at(0)) <= J_PT->at(index.at(1))){
    int temporal = index.at(0);
    index.at(0)=index.at(1);
    index.at(1)=temporal;
  }
}
Float_t calculateE(Float_t eta, Float_t pt, Float_t mass){
  Float_t theta = TMath::ATan(TMath::Exp(-eta));
  Float_t sin_theta = TMath::Sin(2*theta);
  Float_t p= pt/sin_theta;
  Float_t e = sqrt(pow(p, 2) + pow(mass, 2));
  return e;
}
