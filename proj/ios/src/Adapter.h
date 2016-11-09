#import <view/adapter/BaseAdapter.h>

#include <memory>

#include <component/adapter/AdapterList.h>

@interface AdapterIOS : BaseAdapter
- (id)initWith:(std::shared_ptr<AdapterList>) adapterList;
@end
