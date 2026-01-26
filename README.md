# OrderBook

This project started as a **learning exercise** to understand how financial order books work at a low level and to implement them from scratch in **C++**.

I began by implementing a **Level 1 (L1) order book**, focusing on:
- basic bid/ask handling  
- market vs limit orders  
- price crossing logic  

After getting comfortable with L1 , I extended the project to a **Level 2 (L2) order book**, adding:
- multiple price levels  
- FIFO (price–time priority) at each level  
- partial fills  
- correct resting of remaining quantities  

The current implementation includes a simple **matching engine** that processes buy and sell orders and maintains an L2 book using standard C++ containers.

At this stage, the focus is on **correctness and clarity**, but I am also benchmarking the engine and plan to:
- experiment with **micro-optimizations**
- explore alternative data structures
- reduce latency and improve cache efficiency
- better understand performance trade-offs in matching engines
