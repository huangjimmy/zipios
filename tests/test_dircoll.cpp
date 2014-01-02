

#include "zipios++/zipios-config.h"

#include "zipios++/meta-iostreams.h"
#include <memory>

#include "zipios++/dircoll.h"

using namespace zipios ;

using std::cerr ;
using std::cout ;
using std::endl ;
using std::auto_ptr ;

int main() {
  try {
  
    cout << "Instantiating a DirectoryCollection" << endl ;
    DirectoryCollection collection( "../zipios++" ) ;

    ConstEntryPointer ent = collection.getEntry( "zipios-config.h" ) ;
    if ( ent != 0 ) {
      auto_ptr< istream > is( collection.getInputStream( ent ) ) ;
      
      cout << "Contents of entry, " << ent->getName() << " :" << endl ;
      
      cout << is->rdbuf() ;
    }

    
    cout << "list length : " << collection.size() << endl ;
    
    ConstEntries entries ;
    entries = collection.entries() ;
    
    
    ConstEntries::iterator it ;
    for( it = entries.begin() ; it != entries.end() ; it++)
      cout << *(*it) << endl ;
    
    ent = collection.getEntry( "zipios-config.h" ) ;
    if ( ent != 0 ) {
      auto_ptr< istream > is( collection.getInputStream( ent ) ) ;
      
      cout << "Contents of entry, " << ent->getName() << " :" << endl ;
      
      cout << is->rdbuf() ;
    }
    cout << "end of main()" << endl ;
    
    return 0 ;
  }
  catch( exception &excp ) {
    cerr << "Exception caught in main() :" << endl ;
    cerr << excp.what() << endl ;
  }
  return -1;
}

/** \file
    \anchor example_zip_anchor
    source code to a small program that demonstrates the central elements
    of Zipios++.
*/

/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000  Thomas S�ndergaard
  
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.
  
  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.
  
  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/
