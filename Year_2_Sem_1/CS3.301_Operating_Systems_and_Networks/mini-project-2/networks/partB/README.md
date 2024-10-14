# Networks Part B

## Implementing TCP Functionality using UDP

This code comprises a client-server system that emulates TCP-like behavior over UDP. The primary functionalities include data sequencing (splitting data into smaller chunks) and retransmissions.

1. **Data Sequencing:**
   The sender divides the text into smaller chunks, each with a unique identifier, and shares the total chunk count. The receiver assembles them based on their sequence numbers to reconstruct the complete text.
2. **Retransmission:**
   When a data chunk is received, the receiver acknowledges it with a sequence number. If no ACK is received within 0.1 seconds, the sender resends the chunk without waiting for acknowledgments of previous chunks.

## How It Works

### Server Side Code (Receiver of data, Sends acknowledgement)

- Creates a UDP Socket.
- Receives chunk size and number of chunks from the client (sender).
- Receives chunks from the client, processes its sequence number, and sends back an acknowledgment.
- Stores the chunk data into an array, in order.
- After receiving all chunks, data is aggregated to reconstruct the original string.

### Client Side Code (Sends data)

- Creates a UDP Socket.
- Computes the number of chunks using a fixed chunk size (here, 4 bytes).
- Sends this data to the server (receiver).
- Loops through the chunks, constructs packets, and sends them to the server.
- Checks for acknowledgments for 0.05 seconds.
  - If ACK is received, it is marked off, and the next chunk is sent.
  - If ACK is not received, the loop proceeds to send the next chunk.
- To handle retransmissions, at the start of every loop, a linked list of chunks whose acknowledgments are yet to be received is checked to see if a timeout has occurred.
  - If so, then the particular chunk is retransmitted.
  - Else, the next chunk is sent as usual.

## Difference with Actual TCP

1. We have tried to simulate TCP using UDP, including acknowledgments to guarantee the transmission of data. TCP is a much more complex protocol with much better measures to ensure delivery.
2. The provided code does not implement flow control or congestion control mechanisms, which are crucial aspects of TCP that optimize data transmission and ensure network stability.
3. In the implemented code, sequence numbers are assigned manually to each chunk for data sequencing. In TCP, sequence numbers are dynamically assigned and managed by the protocol to ensure ordered and reliable delivery of data.

## Incorporating Flow Control

To account for flow control, we can incorporate a sliding window mechanism. The sliding window will allow the sender to control the amount of unacknowledged data being sent at a time, preventing overwhelming the receiver or the network. We'll also update the receiver to handle this sliding window.

1. On the sender's side, we can modify the packet structure to include the window size.
2. This can then be communicated to the receiver, who can keep track of the data transmission and adjust its window size accordingly.

This facilitates proper flow control and ensures that the sender does not overwhelm the receiver with too much unacknowledged data at the same time.

## Summary

The client-server system emulates TCP-like behavior over UDP by implementing data sequencing and retransmissions.

## Assumptions made
- Client is the party that sends data to the server.
- Server only receives the data and sends back an acknowledgement for the packet received.

## References

- [UDP on Wikipedia](https://en.wikipedia.org/wiki/User_Datagram_Protocol)
- [TCP on Wikipedia](https://en.wikipedia.org/wiki/Transmission_Control_Protocol)
- [ChatGPT Prompts](https://chat.openai.com/share/3b070c92-64f7-4343-bc3a-9b690d7e9da9)
