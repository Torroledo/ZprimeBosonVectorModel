#include <iostream>
#include <time.h>
#include <vector>

void histogramsCollapse(){

  gROOT->Reset();
  gStyle->SetOptStat(0); 
  // Load input data                                                           
  TFile * inputFile = new TFile("collapsedROOTNtuples/collapsedTree.root", "READ");

  // Getting TTrees from TFiles  
  TTree * totalSimulation = (TTree*) inputFile->Get("totalSimulation");

  // Create output Data                                                        
  //TFile * outputFile = new TFile("plots/histograms_mix.root", "RECREATE");

  // OUTPUT VARIABLES                                                    
  // Declaring output variables TAU VARIABLES                                    
  Int_t Tau_Charge,Tau_Charge_1,Tau_Charge_2;
  Float_t Tau_PT_sum,Tau_PT_dif,Tau_PT_1,Tau_PT_2,Tau_Eta_dif,Tau_Eta_1,Tau_Eta_2;
  Float_t Tau_Phi_dif, Tau_Phi_1,Tau_Phi_2;
  Float_t Tau_T;
  Float_t Tau_DeltaEta,Tau_DeltaPhi;
  Float_t Tau_EhadOverEem;

  // Declaring output variables TAGGING                                          
  Int_t BTag,TauTag;

  // Declaring output variables MissET                                           
  Float_t Miss_MET, Miss_Eta, Miss_Phi;

  // Declaring output variables JETS                                             
  Int_t Jet_Charge,Jet_Charge_1,Jet_Charge_2;;
  Float_t Jet_PT_sum,Jet_PT_dif,Jet_PT_1,Jet_PT_2,Jet_Mass_sum,Jet_Mass_dif;
  Float_t Jet_Mass_1,Jet_Mass_2,Jet_Eta_dif,Jet_Eta_1,Jet_Eta_2,Jet_Phi_dif;
  Float_t Jet_Phi_1,Jet_Phi_2,Jet_DeltaEta,Jet_DeltaPhi,Jet_T_1,Jet_T_2;
  Float_t Jet_EhadOverEem_1,Jet_EhadOverEem_2;
  Float_t Jet_BetaStar_1,Jet_BetaStar_2,Jet_MeanSqDeltaR_1,Jet_MeanSqDeltaR_2;
  Float_t Jet_PTD_1,Jet_PTD_2,Jet_Beta_1,Jet_Beta_2;

  Int_t type;

  totalSimulation->SetBranchAddress("type", &type);
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
  totalSimulation->SetBranchAddress("Tau_Charge_1",  &Tau_Charge_1);
  totalSimulation->SetBranchAddress("Tau_Charge_2",  &Tau_Charge_2);
  totalSimulation->SetBranchAddress("Tau_DeltaEta",  &Tau_DeltaEta);
  totalSimulation->SetBranchAddress("Tau_DeltaPhi",  &Tau_DeltaPhi);
  totalSimulation->SetBranchAddress("TauTag",  &TauTag);
  // total 16 vars
  totalSimulation->SetBranchAddress("Miss_MET",  &Miss_MET);
  totalSimulation->SetBranchAddress("Miss_Eta",  &Miss_Eta);
  totalSimulation->SetBranchAddress("Miss_Phi",  &Miss_Phi);
  // total 3 vars
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
  // total vars 31

  // Create a TCanvas.                                                         
  TCanvas* c1 = new TCanvas("c1","Data Exploration Taus",10,10,1000,1000);
  TCanvas* c2 = new TCanvas("c2","Data Exploration Miss",10,10,1000,1000);
  TCanvas* c3 = new TCanvas("c3","Data Exploration Jets",10,10,1000,1200);
  // TCanvas* c3 = new TCanvas("c3","Good Graph",200,10,600,400);
 
  c1->Divide(3,4);
  c2->Divide(2,2);
  c3->Divide(4,5);

  // Create a 1D histogram, set its fill colour, and draw it on the current TPad 
  TH1F * h1  = new TH1F("h1","Tau_PT_sum",100,0.,250.0);
  TH1F * h2  = new TH1F("h2","Tau_PT_dif",100,-250.0,250.0);
  TH1F * h3  = new TH1F("h3","Tau_PT_1",100,0.,250.0);
  TH1F * h4  = new TH1F("h4","Tau_PT_2",100,0.,250.0);
  TH1F * h5  = new TH1F("h5","Tau_Eta_dif",100,0.,-5.0);
  TH1F * h6  = new TH1F("h6","Tau_Eta_1",100,0.,-5.0);
  TH1F * h7  = new TH1F("h7","Tau_Eta_2",100,0.,-5.0);
  TH1F * h8  = new TH1F("h8","Tau_Phi_dif",100,0.,-5.0);
  TH1F * h9  = new TH1F("h9","Tau_Phi_1",100,0.,-5.0);
  TH1F * h10  = new TH1F("h10","Tau_Phi_2",100,0.,-5.0);
  TH1F * h11  = new TH1F("h11","Tau_DeltaEta",100,0.,-5.0);  
  TH1F * h12  = new TH1F("h12","Tau_DeltaPhi",100,0.,-5.0);

  TH1F * h30  = new TH1F("h30","Miss_MET",100,0.,200.0);
  TH1F * h31  = new TH1F("h31","Miss_Eta",100,0.,-5.0);
  TH1F * h32  = new TH1F("h32","Miss_Phi",100,0.,-5.0);

  TH1F * h50  = new TH1F("h50","Jet_PT_sum",100,-10.,300.0);
  TH1F * h51  = new TH1F("h51","Jet_PT_dif",100,-200.0,200.0);
  TH1F * h52  = new TH1F("h52","Jet_PT_1",100,-10.,160.0);
  TH1F * h53  = new TH1F("h53","Jet_PT_2",100,-10.,160.0);
  TH1F * h54  = new TH1F("h54","Jet_Mass_sum",100,0.,50.0);
  TH1F * h55  = new TH1F("h55","Jet_Mass_dif",100,-30.0,30.0);
  TH1F * h56  = new TH1F("h56","Jet_Mass_1",100,-5.,40.0);
  TH1F * h57  = new TH1F("h57","Jet_Mass_2",100,-5.,40.0);
  TH1F * h58  = new TH1F("h58","Jet_Eta_dif",100,0.,-5.0);
  TH1F * h59  = new TH1F("h59","Jet_Eta_1",100,0.,-5.0);
  TH1F * h60  = new TH1F("h60","Jet_Eta_2",100,0.,-5.0);
  TH1F * h61  = new TH1F("h61","Jet_Phi_dif",100,0.,-5.0);
  TH1F * h62  = new TH1F("h62","Jet_Phi_1",100,0.,-5.0);
  TH1F * h63  = new TH1F("h63","Jet_Phi_2",100,0.,-5.0);
  TH1F * h64  = new TH1F("h64","Jet_DeltaEta",100,0.,-5.0);
  TH1F * h65  = new TH1F("h65","Jet_DeltaPhi",100,0.,-5.0);
  TH1I * h66  = new TH1I("h66","Jet_Charge_1",100,0.,-5.0);
  TH1I * h67  = new TH1I("h67","Jet_Charge_2",100,0.,-5.0);

  // type==1
  /*
  TH1F * h99  = new TH1F("h100","Tau_PT_sum by type",100,0.,-5.0);
  TH1F * h100  = new TH1F("h99","Tau_PT_sum by type",100,0.,-5.0);
  */
  int numberOfEntries = totalSimulation->GetEntries();
  cout << "Tree  has : " << numberOfEntries << " entries" << endl;
  
  for (int entry = 0; entry < numberOfEntries; ++entry){
    totalSimulation->GetEntry(entry);

    h1->Fill(Tau_PT_sum);
    h2->Fill(Tau_PT_dif);
    h3->Fill(Tau_PT_1);
    h4->Fill(Tau_PT_2);
    h5->Fill(Tau_Eta_dif);
    h6->Fill(Tau_Eta_1);
    h7->Fill(Tau_Eta_2);
    h8->Fill(Tau_Phi_dif);
    h9->Fill(Tau_Phi_1);
    h10->Fill(Tau_Phi_2);
    h11->Fill(Tau_DeltaEta);
    h12->Fill(Tau_DeltaPhi);
    
    h30->Fill(Miss_MET);
    h31->Fill(Miss_Eta);
    h32->Fill(Miss_Phi);

    h50->Fill(Jet_PT_sum);
    h51->Fill(Jet_PT_dif);
    h52->Fill(Jet_PT_1);
    h53->Fill(Jet_PT_2);
    h54->Fill(Jet_Mass_sum);
    h55->Fill(Jet_Mass_dif);
    h56->Fill(Jet_Mass_1);
    h57->Fill(Jet_Mass_2);
    h58->Fill(Jet_Eta_dif);
    h59->Fill(Jet_Eta_1);
    h60->Fill(Jet_Eta_2);
    h61->Fill(Jet_Phi_dif);
    h62->Fill(Jet_Phi_1);
    h63->Fill(Jet_Phi_2);
    h64->Fill(Jet_DeltaEta);
    h65->Fill(Jet_DeltaPhi);
    h66->Fill(Jet_Charge_1);
    h67->Fill(Jet_Charge_2);

    if(type==1){
      //      h18->Fill(type);
      //  h99->Fill(Tau_PT_sum);
    }
    else{
      //  h100->Fill(Tau_PT_sum);
    }

    /*
    if(!(entry%1000)){
      cout << "Entry : "<< entry << endl;
      } 
    */ 
  }

  h1->Scale(1./h1->Integral()); 
  h2->Scale(1./h2->Integral());
  h3->Scale(1./h3->Integral());
  h4->Scale(1./h4->Integral());
  h5->Scale(1./h5->Integral());
  h6->Scale(1./h6->Integral());
  h7->Scale(1./h7->Integral());
  h8->Scale(1./h8->Integral());
  h9->Scale(1./h9->Integral());
  h10->Scale(1./h10->Integral());
  h11->Scale(1./h11->Integral());
  h12->Scale(1./h12->Integral());

  h30->Scale(1./h30->Integral());
  h31->Scale(1./h31->Integral());
  h32->Scale(1./h32->Integral());
 
  h50->Scale(1./h50->Integral());
  h51->Scale(1./h51->Integral());
  h52->Scale(1./h52->Integral());
  h53->Scale(1./h53->Integral());
  h54->Scale(1./h54->Integral());
  h55->Scale(1./h55->Integral());
  h56->Scale(1./h56->Integral());
  h57->Scale(1./h57->Integral());
  h58->Scale(1./h58->Integral());
  h59->Scale(1./h59->Integral());
  h60->Scale(1./h60->Integral());
  h61->Scale(1./h61->Integral());
  h62->Scale(1./h62->Integral());
  h63->Scale(1./h63->Integral());
  h64->Scale(1./h64->Integral());
  h65->Scale(1./h65->Integral());
  h66->Scale(1./h66->Integral());
  h67->Scale(1./h67->Integral());

  c1->cd(1); h1->Draw("hist");
  c1->cd(2); h2->Draw("hist");
  c1->cd(3); h3->Draw("hist");
  c1->cd(4); h4->Draw("hist");
  c1->cd(5); h5->Draw("hist");
  c1->cd(6); h6->Draw("hist");
  c1->cd(7); h7->Draw("hist");
  c1->cd(8); h8->Draw("hist");
  c1->cd(9); h9->Draw("hist");
  c1->cd(10); h10->Draw("hist");
  c1->cd(11); h11->Draw("hist");
  c1->cd(12); h12->Draw("hist");
  c1->cd(0);
  c1->Print("collapsedROOTNtuples/Taus.pdf");

  c2->cd(1); h30->Draw("hist");
  c2->cd(2); h31->Draw("hist");
  c2->cd(3); h32->Draw("hist");
  c2->cd(0);
  c2->Print("collapsedROOTNtuples/Miss.pdf");

  c3->cd(1); h50->Draw("hist");
  c3->cd(2); h51->Draw("hist");
  c3->cd(3); h52->Draw("hist");
  c3->cd(4); h53->Draw("hist");
  c3->cd(5); h54->Draw("hist");
  c3->cd(6); h55->Draw("hist");
  c3->cd(7); h56->Draw("hist");
  c3->cd(8); h57->Draw("hist");
  c3->cd(9); h58->Draw("hist");
  c3->cd(10); h59->Draw("hist");
  c3->cd(11); h60->Draw("hist");
  c3->cd(12); h61->Draw("hist");
  c3->cd(13); h62->Draw("hist");
  c3->cd(14); h63->Draw("hist");
  c3->cd(15); h64->Draw("hist");
  c3->cd(16); h65->Draw("hist");
  c3->cd(17); h66->Draw("hist");
  c3->cd(18); h67->Draw("hist");
  c3->cd(0);
  c3->Print("collapsedROOTNtuples/Jets.pdf");
  
/*
  c3->cd(); 
  h99->Scale(1./h99->Integral());
  h100->Scale(1./h100->Integral());
  h99->GetYaxis()->SetRangeUser(0.0, 0.12);
  h99->GetXaxis()->SetTitle("p_{T}[GeV]");
  h99->GetYaxis()->SetTitle("a.u");
  h99->Draw();
  h100->SetLineColor(kRed);
  h100->Draw("same");

  TLegend* leg = new TLegend (0.7, 0.6, 0.9, 0.9);
  leg->AddEntry(h99, "Signal");
  leg->AddEntry(h100, "BG");
  leg->Draw();
  c3->Print("collapsedROOTNtuples/collapsedHistogramsByType.pdf");
  //c3->SaveAs("histo.root"); */
}
