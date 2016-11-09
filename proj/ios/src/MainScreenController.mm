#import "MainScreenController.h"

#import "Adapter.h"

#include <screen/MainScreen.h>
#include <screen/ScreenHelper.h>

#include <platform/ContextHelper.h>
#include <component/NodectHelper.h>
#include <component/NodectBuilder.h>
#include <component/view/Text.h>
#import <ColorUtils.h>

@implementation MainScreenController
{
	AdapterIOS* _adapter;
}

- (id)init
{
	self = [super initWithName:@"MainScreen"];
	if (self == nil)
	{
		return nil;
	}

	return self;
}

- (void)loadView
{
	[super loadView];

	auto& screen = ScreenHelper::getScreen<MainScreen>(self);

	//Label view
	UILabel* label = [[UILabel alloc] initWithFrame:CGRectMake(10, 70, 300, 50)];
	[self.view addSubview:label];

	NodectHelper::nest(screen.getNativeScreen(),NodectBuilder::createIos("textView",label).addComponent<Text>().build());

	//Table view
    CGRect screenRect = [[UIScreen mainScreen] bounds];
    screenRect.size.height -= 130;
    screenRect.origin.y += 130;
	UITableView* tableView = [[UITableView alloc] initWithFrame:screenRect style:UITableViewStylePlain];
	[self.view addSubview:tableView];

	_adapter = [[AdapterIOS alloc] initWith: std::static_pointer_cast<AdapterList>(screen.getAdapter())];
	[_adapter setData:screen.getAdapter()->getData()];

	tableView.delegate = _adapter;
	tableView.dataSource = _adapter;

	tableView.backgroundColor = UIColorFromRGB(0xedebef);
	tableView.separatorStyle = UITableViewCellSeparatorStyleNone;
}

@end
