//
//  main.m
//  test
//
//  Created by jimmy on 1/13/15.
//  Copyright (c) 2015 org. All rights reserved.
//

#include "zipios++/zipios-config.h"
#include "zipios++/meta-iostreams.h"
#include <memory>

#include "zipios++/zipfile.h"

#import <Foundation/Foundation.h>

using namespace zipios;
using std::cerr ;
using std::cout ;
using std::endl ;
using std::auto_ptr ;

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
    }
    
    ZipFile zf( "/Users/jimmy/logs.zip" ) ;
    
    
    cout << "list length : " << zf.size() << endl ;
    ConstEntries entries ;
    entries = zf.entries() ;
    
    ConstEntries::iterator it ;
    for( it = entries.begin() ; it != entries.end() ; it++)
        cout << *(*it) << endl ;
    
    string filename("logs/application.log");
    ConstEntryPointer ent = zf.getEntry(filename, FileCollection::MATCH ) ;
    auto_ptr< istream > is( zf.getInputStream( filename, FileCollection::MATCH) ) ;
    
    cout << "Contents of entry, " << ent->getName() << " :" << endl ;
    cout << is->rdbuf() ;
    
    return 0;
}
