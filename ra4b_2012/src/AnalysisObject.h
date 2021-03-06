#ifndef AnalysisObject_h
#define AnalysisObject_h

#include "Math/VectorUtil.h"
#include "NtupleTools2_h.h"
#include <map>
#include <TString.h>
#include <boost/shared_ptr.hpp>
#include "typedefs.h"

using namespace std;
using namespace ROOT::Math::VectorUtil;

//typedef boost::shared_ptr<LorentzM> Ptr_LorentzM;

class AnalysisObject {
  
protected:

  LorentzM  p4;
  LorentzM* pp4_original; 
  Ptr_LorentzM owned_pp4_original;
  std::map<std::string, bool> id;
  int       maptotree;
  //map< string, bool> IDMap() const; 

  //does the instance own the LorentzM?
  bool ownsP4;
public:
  
  AnalysisObject();
  AnalysisObject(const AnalysisObject& copy);
  ~AnalysisObject();

  LorentzM P4() const;
  //boost::shared_ptr<LorentzM> pOriginalP4() const;
  LorentzM* pOriginalP4() const;
  

  double Pt() const;
  double pt() const;
  double Eta() const;
  double eta() const;
  double Phi() const;
  double phi() const;

  double E() const;
  double e() const;
  double Px() const;
  double px() const;
  double Py() const;
  double py() const;
  double Pz() const;
  double pz() const;

  int GetIndexInTree() const;

  bool IsID(const string & id) const;
  void SetID(const string & key, bool value);

  //Set with a lorentz vector that is NOT owned
  void Set(const int maptotree_In,  LorentzM * const momentum_In);
  //void Set(const int maptotree_In,  LorentzM * momentum_In);
  void Set(const int maptotree_In, Ptr_LorentzM momentum_In);

  //
  //Set with a lorentz vector that IS owned
  void SetOwnedPointer(const int maptotree_In, LorentzM* const momentum_In);
  void SetExternalPointer(const int maptotree_In, LorentzM* const momentum_In);

  void SetP4(const LorentzM & p4_in) {p4 = p4_in;}
};

#endif
