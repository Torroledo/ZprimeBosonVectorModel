#include <iostream>
#include <algorithm>
#include <time.h>

void writeFile(std::string inFolder, std::string outFolder, std::string signal);
void exportDataToCSV(){

  // 1. Load each Tree individually 
  std::string inFolder = "randomSampleNoCuts/";

  std::string signal2 = "joined_signal_0p5TeV.root";
  std::string signal3 = "joined_signal_1p0TeV.root";
  std::string signal4 = "joined_signal_1p25TeV.root";
  std::string signal5 = "joined_signal_2p0TeV.root";
    
  writeFile(inFolder, inFolder, signal2);
  writeFile(inFolder, inFolder, signal3);
  writeFile(inFolder, inFolder, signal4);
  writeFile(inFolder, inFolder, signal5);
}
 
void writeFile(std::string inFolder, std::string outFolder, std::string filename){
  
  // Loading signal data from .root file       
  TFile* signalFile1 = new TFile((inFolder + filename).c_str());
  TTree* treeSignal = (TTree *) signalFile1->Get("totalSimulation");
    
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
  Int_t BTag,TauTag,type,type_2;
  
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

  // Number of entries
  int signalEntries = treeSignal->GetEntries();

  cout << "\nTree " << filename << " has : " << signalEntries << " entries" << endl;

  // printing variable names

  ofstream myfile;
  std::string ext = ".csv";
  myfile.open((outFolder+filename+ext).c_str());
  myfile << "Tau_PT_sum,Tau_PT_dif,Tau_PT_1,Tau_PT_2,Tau_Mass_sum,Tau_Mass_dif,Tau_Mass_1,Tau_Mass_2,Tau_Ener_sum, Tau_Ener_1, Tau_Ener_2,Tau_Eta_dif,Tau_Eta_1,Tau_Eta_2,type,type_2,Miss_MET,Jet_PT_sum,Jet_PT_dif,Jet_PT_1,Jet_PT_2,Jet_Mass_sum,Jet_Mass_dif,Jet_Mass_1,Jet_Mass_2,Jet_Ener_sum,Jet_Ener_1,Jet_Ener_2,Jet_Eta_dif,Jet_Eta_1,Jet_Eta_2"<<endl;

  for (int sample_i = 0; sample_i < signalEntries; ++sample_i){
    treeSignal->GetEntry(sample_i);
    myfile <<Tau_PT_sum<<","<<Tau_PT_dif<<","<<Tau_PT_1<<","<<Tau_PT_2<<","<<Tau_Mass_sum<<","<<Tau_Mass_dif<<","<<Tau_Mass_1<<","<<Tau_Mass_2<<","<<Tau_Ener_sum<<","<< Tau_Ener_1<<","<< Tau_Ener_2<<","<<Tau_Eta_dif<<","<<Tau_Eta_1<<","<<Tau_Eta_2<<","<<type<<","<<type_2<<","<<Miss_MET<<","<<Jet_PT_sum<<","<<Jet_PT_dif<<","<<Jet_PT_1<<","<<Jet_PT_2<<","<<Jet_Mass_sum<<","<<Jet_Mass_dif<<","<<Jet_Mass_1<<","<<Jet_Mass_2<<","<<Jet_Ener_sum<<","<<Jet_Ener_1<<","<<Jet_Ener_2<<","<<Jet_Eta_dif<<","<<Jet_Eta_1<<","<<Jet_Eta_2<<endl;
    
    if(!(sample_i%500)){
      cout << "Entryi : "<< sample_i << endl;
    }
  }
  myfile.close();
}
