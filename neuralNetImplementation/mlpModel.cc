//---------------------------------------------------------------------------
// Multilayer Perceptron Model for a signal to background classification 
// problem Search of a Z' vector Boson at LHC
// 
// by Iván Torroledo 
//---------------------------------------------------------------------------

void mlpModel(){
  
  // Loading MLP class if it don't exist
  if (!gROOT->GetClass("TMultiLayerPerceptron")) {
    gSystem->Load("libMLP");
    cout << "MLP lib loaded! :)"<< endl;
  }
  
  // Model Parameters
  ntrain = 500;
  
  // Loading Data  
  TFile* inputFile = new TFile("fourCollapsedROOTNtuples/collapsedTree.root");
  TTree* totalSimulation = (TTree *) inputFile->Get("totalSimulation");

  // TAU VARIABLES                                             
  Int_t Tau_Charge, Tau_Charge_1, Tau_Charge_2;
  Float_t Tau_PT_sum,Tau_PT_dif,Tau_PT_1,Tau_PT_2,Tau_Eta_dif,Tau_Eta_1,Tau_Eta_2;
  Float_t Tau_Phi_dif, Tau_Phi_1,Tau_Phi_2,Tau_DeltaEta,Tau_DeltaPhi;
  Float_t Tau_EhadOverEem;
  // TAGGING VARIABLES                                                   
  Int_t BTag,TauTag;
  // MISSING ET VARIABLES                                                    
  Float_t Miss_MET, Miss_Eta, Miss_Phi;
  // JETS VARIABLES                                                      
  Int_t Jet_Charge,Jet_Charge_1,Jet_Charge_2;
  Float_t Jet_PT_sum,Jet_PT_dif,Jet_PT_1,Jet_PT_2,Jet_Mass_sum,Jet_Mass_dif;
  Float_t Jet_Mass_1,Jet_Mass_2,Jet_Eta_dif,Jet_Eta_1,Jet_Eta_2,Jet_Phi_dif;
  Float_t Jet_Phi_1,Jet_Phi_2,Jet_DeltaEta,Jet_DeltaPhi,Jet_T_1,Jet_T_2;
  Float_t Jet_EhadOverEem_1,Jet_EhadOverEem_2;
  Float_t Jet_BetaStar_1,Jet_BetaStar_2,Jet_MeanSqDeltaR_1,Jet_MeanSqDeltaR_2;
  Float_t Jet_PTD_1,Jet_PTD_2,Jet_Beta_1,Jet_Beta_2;
  Int_t type,type_2;
  totalSimulation->SetBranchAddress("type", &type);
  totalSimulation->SetBranchAddress("type_2", &type_2);
  totalSimulation->SetBranchAddress("Tau_PT_sum",  &Tau_PT_sum);
  totalSimulation->SetBranchAddress("Tau_PT_dif",  &Tau_PT_dif);
  totalSimulation->SetBranchAddress("Tau_PT_1",  &Tau_PT_1);
  totalSimulation->SetBranchAddress("Tau_PT_2",  &Tau_PT_2);
  totalSimulation->SetBranchAddress("Tau_Eta_dif",  &Tau_Eta_dif);
  totalSimulation->SetBranchAddress("Tau_Eta_1",  &Tau_Eta_1);
  totalSimulation->SetBranchAddress("Tau_Eta_2",  &Tau_Eta_2);
  totalSimulation->SetBranchAddress("Tau_Phi_dif",  &Tau_Phi_dif);
  totalSimulation->SetBranchAddress("Tau_Phi_1",  &Tau_Phi_1);
  totalSimulation->SetBranchAddress("Tau_Phi_2",  &Tau_Phi_2);
  totalSimulation->SetBranchAddress("Tau_DeltaEta",  &Tau_DeltaEta);
  totalSimulation->SetBranchAddress("Tau_DeltaPhi",  &Tau_DeltaPhi);
  totalSimulation->SetBranchAddress("Tau_Charge_1",  &Tau_Charge_1);
  totalSimulation->SetBranchAddress("Tau_Charge_2",  &Tau_Charge_2);
  totalSimulation->SetBranchAddress("TauTag",  &TauTag);

  totalSimulation->SetBranchAddress("Miss_MET",  &Miss_MET);
  totalSimulation->SetBranchAddress("Miss_Eta",  &Miss_Eta);
  totalSimulation->SetBranchAddress("Miss_Phi",  &Miss_Phi); 

  totalSimulation->SetBranchAddress("Jet_PT_sum",   &Jet_PT_sum);
  totalSimulation->SetBranchAddress("Jet_PT_dif",   &Jet_PT_dif);
  totalSimulation->SetBranchAddress("Jet_PT_1",   &Jet_PT_1);
  totalSimulation->SetBranchAddress("Jet_PT_2",   &Jet_PT_2);
  totalSimulation->SetBranchAddress("Jet_Mass_sum", &Jet_Mass_sum);
  totalSimulation->SetBranchAddress("Jet_Mass_dif", &Jet_Mass_dif);
  totalSimulation->SetBranchAddress("Jet_Mass_1", &Jet_Mass_1);
  totalSimulation->SetBranchAddress("Jet_Mass_2",&Jet_Mass_2);
  totalSimulation->SetBranchAddress("Jet_Eta_dif",  &Jet_Eta_dif);
  totalSimulation->SetBranchAddress("Jet_Eta_1",  &Jet_Eta_1);
  totalSimulation->SetBranchAddress("Jet_Eta_2",  &Jet_Eta_2);
  totalSimulation->SetBranchAddress("Jet_Phi_dif",  &Jet_Phi_dif);
  totalSimulation->SetBranchAddress("Jet_Phi_1",  &Jet_Phi_1);
  totalSimulation->SetBranchAddress("Jet_Phi_2",  &Jet_Phi_2);
  totalSimulation->SetBranchAddress("Jet_DeltaEta",    &Jet_DeltaEta);
  totalSimulation->SetBranchAddress("Jet_DeltaPhi",    &Jet_DeltaPhi);
  totalSimulation->SetBranchAddress("Jet_T_1",    &Jet_T_1);
  totalSimulation->SetBranchAddress("Jet_T_2",    &Jet_T_2);
  totalSimulation->SetBranchAddress("Jet_Charge_1",  &Jet_Charge_1);
  totalSimulation->SetBranchAddress("Jet_Charge_2",  &Jet_Charge_2);
  totalSimulation->SetBranchAddress("Jet_EhadOverEem_1", &Jet_EhadOverEem_1);
  totalSimulation->SetBranchAddress("Jet_EhadOverEem_2", &Jet_EhadOverEem_2);
  totalSimulation->SetBranchAddress("BTag", &BTag);

  //-------------------------------------------------------------------------
  // WARNING !!
  // Machine Learning Zone 
  //-------------------------------------------------------------------------
  // First generation
  /* std::string inputTauFeatures1 = "@Tau_Phi_dif,@Tau_PT_sum,@Tau_PT_1,Tau_PT_2,";
  stdd::string inputJetFeatures1  = "@Jet_Eta_dif,@Jet_Eta_1,@Jet_Eta_2";
  // Second generation
  std::string inputMissFeatures2 = "@Miss_MET,@Miss_Eta,@Miss_Phi";
  // Total features
  std::string features = inputTauFeatures1 + inputJetFeatures1;

  std::string architecture = ":7:11:10:10:10:7:3:type";
  std::string model = features + architecture;
  */
  //  TMultiLayerPerceptron* mlp = new TMultiLayerPerceptron("@Tau_Phi_dif,@Tau_PT_sum,@Tau_PT_1,Tau_PT_2,@Jet_Eta_dif,@Jet_Eta_1,@Jet_Eta_2:15:3:type",totalSimulation);
 
  TMultiLayerPerceptron* mlp = new TMultiLayerPerceptron("@Jet_Eta_dif,@Jet_Eta_1,@Jet_Eta_2,@Tau_Phi_dif,@Jet_PT_sum,@Tau_PT_sum,@Tau_PT_1,:5:type",totalSimulation); 
  //7:5:3:
  //  mlp->SetLearningMethod(TMultiLayerPerceptron::kStochastic);
  //  TMultiLayerPerceptron::SetEventWeight()   
  //  TMultiLayerPerceptron::Evaluate() 
  // TMultiLayerPerceptron::Export() 
  // drawResult()
  cout << "Multi Layer Perceptron initialized" << endl;
  mlp->Train(ntrain, "text,update=1");
  mlp->Export("test","python");


  // GRAPHS
  TCanvas *c1 = new TCanvas("c1","Output Distributions");
  c1->cd();
  mlp->DrawResult(0,"conv");
  // Use TMLPAnalyzer to see what it looks for                     
  TCanvas* mlpa_canvas = new TCanvas("mlpa_canvas","Network analysis");
  mlpa_canvas->Divide(2,2);
  TMLPAnalyzer ana(mlp);
  // Initialisation                                                
  ana.GatherInformations();
  // output to the console                                         
  ana.CheckNetwork();
  mlpa_canvas->cd(1);
  // shows how each variable influences the network                
  ana.DrawDInputs();
  mlpa_canvas->cd(2);

  // shows the network structure                                   
  mlp->Draw();

  mlpa_canvas->cd(3);
  // draws the resulting network                                   
  ana.DrawNetwork(0,"type==1","type==0");
}
