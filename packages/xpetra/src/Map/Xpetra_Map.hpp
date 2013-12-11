// @HEADER
//
// ***********************************************************************
//
//             Xpetra: A linear algebra interface package
//                  Copyright 2012 Sandia Corporation
//
// Under the terms of Contract DE-AC04-94AL85000 with Sandia Corporation,
// the U.S. Government retains certain rights in this software.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
// 1. Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer in the
// documentation and/or other materials provided with the distribution.
//
// 3. Neither the name of the Corporation nor the names of the
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY SANDIA CORPORATION "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL SANDIA CORPORATION OR THE
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
// LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
// NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Questions? Contact
//                    Jonathan Hu       (jhu@sandia.gov)
//                    Andrey Prokopenko (aprokop@sandia.gov)
//                    Ray Tuminaro      (rstumin@sandia.gov)
//
// ***********************************************************************
//
// @HEADER
#ifndef XPETRA_MAP_HPP
#define XPETRA_MAP_HPP

/* this file is automatically generated - do not edit (see script/interfaces.py) */

#include <Kokkos_DefaultNode.hpp>
#include <Teuchos_Describable.hpp>
#include "Xpetra_ConfigDefs.hpp"

namespace Xpetra {

  enum UnderlyingLib {
    UseEpetra,
    UseTpetra,
    NotSpecified
  };

  template <class LocalOrdinal, class GlobalOrdinal = LocalOrdinal, class Node = KokkosClassic::DefaultNode::DefaultNodeType>
  class Map
    : public Teuchos::Describable
  {

  public:

    //! @name Constructor/Destructor Methods
    //@{

    //! Destructor.
    virtual ~Map() { }

   //@}

    //! @name Attributes
    //@{

    //! The number of elements in this Map.
    virtual global_size_t getGlobalNumElements() const = 0;

    //! The number of elements belonging to the calling node.
    virtual size_t getNodeNumElements() const = 0;

    //! The index base for this Map.
    virtual GlobalOrdinal getIndexBase() const = 0;

    //! The minimum local index.
    virtual LocalOrdinal getMinLocalIndex() const = 0;

    //! The maximum local index on the calling process.
    virtual LocalOrdinal getMaxLocalIndex() const = 0;

    //! The minimum global index owned by the calling process.
    virtual GlobalOrdinal getMinGlobalIndex() const = 0;

    //! The maximum global index owned by the calling process.
    virtual GlobalOrdinal getMaxGlobalIndex() const = 0;

    //! The minimum global index over all processes in the communicator.
    virtual GlobalOrdinal getMinAllGlobalIndex() const = 0;

    //! The maximum global index over all processes in the communicator.
    virtual GlobalOrdinal getMaxAllGlobalIndex() const = 0;

    //! The local index corresponding to the given global index.
    virtual LocalOrdinal getLocalElement(GlobalOrdinal globalIndex) const = 0;

    //! The global index corresponding to the given local index.
    virtual GlobalOrdinal getGlobalElement(LocalOrdinal localIndex) const = 0;

    //! Return the process IDs and corresponding local IDs for the given global IDs.
    virtual LookupStatus getRemoteIndexList(const Teuchos::ArrayView< const GlobalOrdinal > &GIDList, const Teuchos::ArrayView< int > &nodeIDList, const Teuchos::ArrayView< LocalOrdinal > &LIDList) const = 0;

    //! Return the process IDs for the given global IDs.
    virtual LookupStatus getRemoteIndexList(const Teuchos::ArrayView< const GlobalOrdinal > &GIDList, const Teuchos::ArrayView< int > &nodeIDList) const = 0;

    //! Return a view of the global indices owned by this node.
    virtual Teuchos::ArrayView< const GlobalOrdinal > getNodeElementList() const = 0;

    //@}

    //! @name Boolean tests
    //@{

    //! True if the local index is valid for this Map on this node, else false.
    virtual bool isNodeLocalElement(LocalOrdinal localIndex) const = 0;

    //! True if the global index is found in this Map on this node, else false.
    virtual bool isNodeGlobalElement(GlobalOrdinal globalIndex) const = 0;

    //! True if this Map is distributed contiguously, else false.
    virtual bool isContiguous() const = 0;

    //! Whether this Map is globally distributed or locally replicated.
    virtual bool isDistributed() const = 0;

    //! True if and only if map is compatible with this Map.
    virtual bool isCompatible(const Map< LocalOrdinal, GlobalOrdinal, Node > &map) const = 0;

    //! True if and only if map is identical to this Map.
    virtual bool isSameAs(const Map< LocalOrdinal, GlobalOrdinal, Node > &map) const = 0;

    //@}

    //! @name
    //@{

    //! Get this Map's Comm object.
    virtual const Teuchos::RCP< const Teuchos::Comm< int > >  getComm() const = 0;

    //! Get this Map's Node object.
    virtual const Teuchos::RCP< Node >  getNode() const = 0;

    //@}

    //! @name
    //@{

    //! Return a simple one-line description of this object.
    virtual std::string description() const = 0;

    //! Print this object with the given verbosity level to the given FancyOStream.
    virtual void describe(Teuchos::FancyOStream &out, const Teuchos::EVerbosityLevel verbLevel=Teuchos::Describable::verbLevel_default) const = 0;

    virtual RCP<const Map> removeEmptyProcesses  () const = 0;
    virtual RCP<const Map> replaceCommWithSubset (const Teuchos::RCP<const Teuchos::Comm<int> >& newComm) const = 0;

    //@}

    //! @name Xpetra specific
    //@{

    //! Get the library used by this object (Tpetra or Epetra?)
    virtual UnderlyingLib lib() const = 0;

    //@}

  }; // Map class

} // Xpetra namespace

#define XPETRA_MAP_SHORT
#endif // XPETRA_MAP_HPP
