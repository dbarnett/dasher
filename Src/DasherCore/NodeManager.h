#ifndef __nodemanager_h__
#define __nodemanager_h__

#include "DasherTypes.h"

namespace Dasher {
  class CDasherNode; // Forward declaration

  ///
  /// Virtual base class for node managers
  ///
  
  class CNodeManager {
  public:
    ///
    /// Increment reference count
    ///

    virtual void Ref() = 0;
    
    ///
    /// Decrement reference count
    ///
    
    virtual void Unref() = 0;

    ///
    /// Get a new root node owned by this manager
    ///

    virtual CDasherNode *GetRoot(CDasherNode *pParent, int iLower, int iUpper, void *pUserData) = 0;

    ///
    /// Provide children for the supplied node
    ///

    virtual void PopulateChildren( CDasherNode *pNode ) = 0;
    
    ///
    /// Delete any storage alocated for this node
    ///

    virtual void ClearNode( CDasherNode *pNode ) = 0;

    ///
    /// Called whenever a node belonging to this manager first 
    /// moves under the crosshair
    ///

    virtual void Output( CDasherNode *pNode, Dasher::VECTOR_SYMBOL_PROB* pAdded, int iNormalization) {};
    virtual void Undo( CDasherNode *pNode ) {};

    virtual void Enter(CDasherNode *pNode) {};
    virtual void Leave(CDasherNode *pNode) {};

    virtual CDasherNode *RebuildParent(CDasherNode *pNode, int iGeneration) {
      return 0;
    }
  };

}

#endif