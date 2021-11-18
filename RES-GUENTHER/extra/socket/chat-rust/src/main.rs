// author: Oliver Kogel
// description: This program demonstrates a simple UDP socket chat application

use std::env;
use std::io;
use std::net::UdpSocket;
use std::str;
use std::thread;

// a little Rust sidenote:
// some functions can throw errors, unwrap() is a helper function
// to make sure everything is ok or end the program if it isn't
// ideally errors should be handled more gracefully

// hardcode the client and server addresses
const SERVER_ADDR: &str = "127.0.0.1:6000";
const CLIENT_ADDR: &str = "127.0.0.1:6001";
// hardcode a buffer size of 4096 bytes
// if a sent messages exceeds this size, the program will panic!
const BUFFER_SIZE: usize = 4096;

fn main() {
    // save commands line arguments to args
    let args: Vec<String> = env::args().collect();

    // parse command line arguments
    // if first argument == "server", we run in server mode
    if args.len() > 1 && args[1] == "server" {
        server().unwrap();
    } else {
        client().unwrap();
    }
}

// initialize the server side
fn server() -> std::io::Result<()> {
    {
        println!("Hello, I am the Server.");

        // bind the socket!
        let socket = UdpSocket::bind(SERVER_ADDR)?;
        // initalize an empty byte buffer
        let mut buffer = [0; BUFFER_SIZE];

        // wait for a message from the client, read it into the buffer
        // amt is the amount of bytes received
        // src is the sender's address
        let (amt, src) = socket.recv_from(&mut buffer)?;

        println!("Server: {} bytes read from source {}!", amt, src);
        println!(
            "Server: Message received from client: {}",
            str::from_utf8(&buffer).unwrap()
        );

        // now that we know who the client is, we can enter the messaging loop
        messaging_loop(src, socket).unwrap();
    }
    Ok(())
}

// initialize the client side
fn client() -> std::io::Result<()> {
    {
        println!("Hello, I am the Client.");

        // bind the socket!
        let socket = UdpSocket::bind(CLIENT_ADDR)?;
        let buffer = "Hello Server!".as_bytes();

        // send an initial message to the server, so it knows who we are
        socket
            .send_to(&buffer, SERVER_ADDR)
            .expect("Could not send message!");

        // enter the messaging loop
        messaging_loop(SERVER_ADDR.parse().unwrap(), socket).unwrap();
    }
    Ok(())
}

// once client/server is set up and ready, we can start chatting in here
fn messaging_loop(addr: std::net::SocketAddr, socket_read_handle: UdpSocket) -> io::Result<()> {
    // copy the passed socket handle, so we don't run into scope/threading issues
    // Rust is a little pedantic when it comes to that
    // we are stilling using the same socket though, we are just creating another independantly owned HANDLE
    let socket_write_handle = socket_read_handle.try_clone().unwrap();

    // UI thread
    // this is where we interact with the user and send those messages to the recipient
    thread::spawn(move || {
        // obtain a handle for stdin
        let stdin = io::stdin();
        // define a buffer to read our message into
        // this time it's just a regular String object
        // we convert it to a byte array later!
        let mut buffer = String::new();

        loop {
            // read a line from stdin
            stdin.read_line(&mut buffer).unwrap();
            // convert the input to a byte array and send it to the recipient
            socket_write_handle
                .send_to(&buffer.as_bytes(), addr)
                .expect("Could not send message!");
        }
    });

    // receiving on the main thread
    // this is where we listen for new messages
    loop {
        // define an empty buffer, to read our message into
        let mut buf = [0; BUFFER_SIZE];

        // wait for a message from the sender
        let (_amt, _src) = socket_read_handle.recv_from(&mut buf)?;

        // print the message
        println!("Message: {}", str::from_utf8(&buf).unwrap());
    }
}
