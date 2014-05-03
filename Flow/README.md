Aggregation and sorting of flow data
====================================

The aim of the project is the effective implementation of algorithms for sorting and aggregation of network flow data. The program processes a binary file (specifcally adjusted output of nfdump) with stored flows andit will aggregate and sort flows. The program 'fdump' represents the currently existing solution that behaves in the similar way.

How to run
----------

    flow -f directory -a aggregation -s sorting
  
    -a
        srcip = IPv4/32 or IPv6/128
        srcip4/mask = IPv4/1-32
        srcip6/mask = IPv6/1-128
    -s
        bytes
        packets
