# Socket-stuff
 The goal of this project is to learn more about sockets.
 
# What is a socket?
A socket is one endpoint of a two-way communication link between two programs running on the network.

An endpoint is a combination of an IP address and a port number.

# client-server model
The client-server model is one of the most used communication paradigms in networked systems.  

Clients normally communicates with one server at a time.  

From a server’s perspective, at any point in time, it is not unusual for a server to be communicating with multiple clients. 

Client need to know of the existence of and the address of the server, but the server does not need to know the address of (or even the existence of) the client prior to the connection being established.

# How to create a socket?
When we create a socket we need to define 3 arguments:

* domain
* type
* protocol

socket(domain, type, protocol)

This creates an endpoint for communication and returns a **file descriptor** that refers to that endpoint.  

* On success, a file descriptor for the new socket is returned.  
* On error, -1 is returned, and errno is set appropriately.

## domain
The domain argument specifies a communication domain; this selects the protocol family which will be used for communication.

## type
The type argument specifies the semantics of communication.

## protocol
The protocol parameter specifies a particular protocol to be used with the socket.  
In most cases, a single protocol exists to support a particular type of socket in a particular addressing family.   

If the protocol parameter is set to 0, the system selects the default protocol number for the domain and socket type requested.

