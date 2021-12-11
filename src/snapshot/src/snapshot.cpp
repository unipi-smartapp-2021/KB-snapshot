#include "mongodb_store/message_store.h"
#include <boost/foreach.hpp>
#include "runtime/Custom_Message.h"

#include <sstream>
#include <cassert>

using namespace mongodb_store;
using namespace std;
using namespace runtime;
/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
	ros::init(argc, argv, "example_mongodb_store_cpp_client");
	ros::NodeHandle nh;

	//Create object which does the work for us.
	MessageStoreProxy messageStore(nh);

    vector< boost::shared_ptr<Custom_Message> > results;

    // get all poses, should show updated named position  
	messageStore.query<Custom_Message>(results);
	BOOST_FOREACH( boost::shared_ptr<Custom_Message> p,  results)
	{
		ROS_INFO_STREAM("Got: " << *p);
	}

    // messageStore.query<Pose>(results, mongo::BSONObj(), mongo::BSONObj(),mongo::BSONObj(), false, 2); // limit=2
    // ROS_INFO_STREAM("Got: " << results.size() << " messages.");
        
	return 0;
}

