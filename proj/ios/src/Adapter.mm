#import "Adapter.h"

#include <platform/Context.h>
#include <component/adapter/AdapterList.h>
#include <log.h>
#include <platform/ContextHelper.h>
#include <component/view/Text.h>
#include <component/view/Image.h>
#import <ColorUtils.h>

@implementation AdapterIOS
{
}

- (id)initWith:(std::shared_ptr<AdapterList>) adapterList
{
	self = [super init];
	if (self == nil)
	{
		return nil;
	}
    
	[self addCreatorFor:@"element"
				creator:^UIView*(NSIndexPath* indexPath, NSString* identifier) {
					UITableViewCell* cellView =
						[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
						cellView.backgroundColor = UIColorFromRGB(0xedebef);
						return cellView;
				}
				  seter:^void(UIView* cellView, NSIndexPath* indexPath, const Poco::Any& data) {
					  UITableViewCell* myCell = (UITableViewCell*)cellView;
					  adapterList->setElement(indexPath.row,NodectBuilder::createIos("row",myCell).nest(
						  NodectBuilder::createIos("text",myCell.textLabel).addComponent<Text>().build()
					  ).nest(
						  NodectBuilder::createIos("image",myCell.imageView).addComponent<Image>().build()
					  ).build());
		  		  }];

	[self addCreatorFor:@"empty"
				creator:^UIView*(NSIndexPath* indexPath, NSString* identifier) {
					UITableViewCell* cellView =
						[[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identifier];
					cellView.hidden = YES;
					cellView.opaque = NO;
					cellView.backgroundColor = nil;
					cellView.selectionStyle = UITableViewCellSelectionStyleNone;
					return cellView;
				}];

	return self;
}

- (CGFloat)tableView:(UITableView*)tableView heightForRowAtIndexPath:(NSIndexPath*)indexPath
{
	NSString* identifier = [self getIdentifierAt:(int)indexPath.row];
	if ([identifier isEqualToString:@"element"])
	{
		return 60;
	}

	return 10;
}

@end
