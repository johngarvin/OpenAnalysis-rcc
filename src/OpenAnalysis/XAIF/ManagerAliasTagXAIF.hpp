/*! \file
  
  \brief Declarations of the AnnotationManager that generates a 
         AliasMapXAIF.   These don't satisfy the AliasMap::Interface
         because they are a filtered version of AliasMap specifically
         for XAIF.

  \authors Michelle Strout
  \version $Id: ManagerAliasMapXAIF.hpp,v 1.6 2004/11/24 16:49:32 mstrout Exp $

  Copyright (c) 2002-2005, Rice University <br>
  Copyright (c) 2004-2005, University of Chicago <br>
  Copyright (c) 2006, Contributors <br>
  All rights reserved. <br>
  See ../../../Copyright.txt for details. <br>


  Special things about AliasMap:
  - Only mappings for top memory reference handles to AliasMap sets are
    provided.
  - This manager calls it maintains a counter for alias map set ids.
    Therefore all procedures that have their AliasMap generated with
    this manager will have unique ids for their alias map sets across
    all AliasMaps except for the zeroth id.

*/

#ifndef ManagerAliasMapXAIF_h
#define ManagerAliasMapXAIF_h

//! ========= OpenAnalysis headers ======================

#include <OpenAnalysis/Utils/OA_ptr.hpp>
#include <OpenAnalysis/UDDUChains/Interface.hpp>
#include <OpenAnalysis/CFG/CFGInterface.hpp>
#include <OpenAnalysis/XAIF/AliasTagXAIF.hpp>
#include <OpenAnalysis/IRInterface/XAIFIRInterface.hpp>

//! ======================================================

namespace OA {

  namespace XAIF {

//! ====================================================================
//! The AnnotationManager for AliasMapXAIF.
//! This class can build an AliasMapXAIF, 
//! (eventually) read one in from a file, and write one out to a file.
//! =====================================================================

class ManagerAliasTagXAIF { //??? eventually public OA::AnnotationManager

public:

    //! =========== Constructor =============

    ManagerAliasTagXAIF(OA_ptr<XAIFIRInterface>);

    //! =========== Destructor ==============

    ~ManagerAliasTagXAIF () {}

    //! ========= Used to perform analysis when not using AQM ==========

    OA_ptr<XAIF::AliasTagXAIF> 
     performAnalysis(ProcHandle, OA_ptr<Alias::Interface> alias);

private:

    OA_ptr<XAIFIRInterface> mIR;    

};


  } // end of XAIF namespace
} // end of OA namespace

#endif

