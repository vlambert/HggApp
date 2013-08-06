#include <VecbosEGObject.hh>

#include <vector>
#include <iostream>
#include <string>

#include <TChain.h>
#include "BaseSelector.hh"

class HggMakeTrainingTree : public BaseSelector{
public:
  HggMakeTrainingTree(vector<string> fNames,string treeName,string outputFile):BaseSelector(fNames,treeName,outputFile){setDoFill(false);}
protected:
  //mandatory overrides
  virtual void processEntry(Long64_t iEntry);
  virtual int init(){ return 0; }
  virtual void processConfig(ReadConfig &cfg);
  virtual void setupOutputTree();
  
  virtual void clear();
  virtual void firstInit();

  //output variables
  int64_t evtNumberOut;

  VecbosPho *outPhoton=0;

  int nVtxOut;
  float rhoOut;
};
