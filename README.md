# KB-snapshot
Snapshot service. 

## Mongodb setting

As usual, launch the __roscore__ and then set parameters for mongodb

```
    rosparam set mongodb_port 62345
    rosparam set mongodb_host bob
```

Then in two separate terminal, launch

```
    rosrun mongodb_store mongodb_server.py
    rosrun mongodb_store message_store_node.py
```

Then run the following node, either 

```
    rosrun snapshot snapshot
```

to retrieve the entire __Custom_Message__ stored. Or run 

```
    rosrun snapshot snapshot.py
```

to filter __Custom_Message__ on a given timedate. 
Please note that you need a mongodb istance saved in 

```
    opt/ros/mongodb_store
```

together with a previously __mongodb_log__ of some topics (in this case was __Custom_Message__)