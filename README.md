---

# 🌐 Simple HTTP Server (C++)

A basic **HTTP server** implemented in **C++** using **Winsock2**. This server listens for incoming connections on port 8080 and serves a simple HTML response to each client.

---

## 🚀 Features

- **Simple HTTP Response** : Returns a basic HTML page with a welcome message.
- **TCP Connection Handling** : Uses Winsock to accept client connections over TCP.
- **Multi-Client Support** : Handles one client at a time (single-threaded)

---

## 🛠 Installation

Make sure you have a C++ compiler that supports Winsock2. For Windows, **Microsoft Visual Studio** is recommended.

1. Clone the repository :

```bash
git clone https://github.com/XanderSteyn/HTTP-Server.git
cd HTTP-Server
```

2. Compile the C++ code with your preferred C++ compiler. Example using **g++** :

```bash
g++ -o HTTPServer HTTPServer.cpp -lws2_32
```

3. Run the compiled program :

```bash
./SimpleHTTPServer.exe
```

---

## 🎮 Usage

After starting the server, you can test it by navigating to **http://localhost:8080** in your browser. You should see the following message :

```html
<h1>This is a Simple HTTP Response</h1>
```

---

## 🛑 How It Works

1. **Socket Initialization** : The server initializes Winsock and creates a TCP socket.
2. **Bind & Listen** : The server binds the socket to port 8080 and listens for incoming connections.
3. **Handle Client Requests** : When a client connects, it receives an HTTP request, which is then processed.
4. **Send Response** : A simple HTML response is sent back to the client.
5. **Close Connection** : After sending the response, the server closes the client connection and waits for the next one.

---

## 📌 Notes

- This is a **single-threaded** server and can handle one client at a time.
- The server listens on **port 8080**. Make sure the port is not in use by another application.
- **Only works on Windows** due to reliance on the **Winsock** library.

---
