#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rospy
import mongodb_store_msgs.srv as dc_srv
import mongodb_store.util as dc_util
from mongodb_store.message_store import MessageStoreProxy
from runtime.msg import Custom_Message
import datetime

if __name__ == "__main__":

    rospy.init_node("example_message_retrieve")


    msg_store = MessageStoreProxy()

    try:
        # some other things you can do...
        # get all poses
        date = datetime.datetime(2021, 11, 23, 15, 12, 4, 88000)

        print(date)

        print(msg_store.query(Custom_Message._type, {"_meta.inserted_at": {"$gt": date}} ))

    except rospy.ServiceException as e:
        print(f"Service call failed: {e}")

