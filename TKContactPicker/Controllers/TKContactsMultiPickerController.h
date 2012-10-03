//
//  TKContactsMultiPickerController.h
//  TKContactsMultiPicker
//
//  Created by Jongtae Ahn on 12. 8. 31..
//  Copyright (c) 2012년 TABKO Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AddressBook/AddressBook.h>
#import <AddressBookUI/AddressBookUI.h>
#import <malloc/malloc.h>
#import "TKAddressBook.h"

@class TKAddressBook, TKContactsMultiPickerController;
@protocol TKContactsMultiPickerControllerDelegate <NSObject>
@required
- (void)tkContactsMultiPickerController:(TKContactsMultiPickerController*)picker didFinishPickingDataWithInfo:(NSArray*)contacts;
- (void)tkContactsMultiPickerControllerDidCancel:(TKContactsMultiPickerController*)picker;
@end


@interface TKContactsMultiPickerController : UIViewController <UITableViewDataSource, UITableViewDelegate, UISearchDisplayDelegate, UISearchBarDelegate>
{
	id _delegate;
    
@private
    NSUInteger _selectedCount;
    NSMutableArray *_listContent;
	NSMutableArray *_filteredListContent;
    
    /** Filters out entries without an email address */
    BOOL _filterNonEmail;
    
    /** Controls if emails are shown with contact names */
    BOOL _showEmails;
}

@property (nonatomic, retain) id<TKContactsMultiPickerControllerDelegate> delegate;
@property (nonatomic, retain) IBOutlet UITableView *tableView;
@property (nonatomic, retain) IBOutlet UISearchBar *searchBar;

@property (nonatomic, copy) NSString *savedSearchTerm;
@property (nonatomic) NSInteger savedScopeButtonIndex;
@property (nonatomic) BOOL searchWasActive;

/** Filters out entries without an email address */
@property (nonatomic) BOOL filterNonEmail;

/** Controls if emails are shown with contact names */
@property (nonatomic) BOOL showEmails;

@end
