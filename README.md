# Centrality Algorithms Computation and Visualization

![Application](visualization/assets/demo.png?raw=true "Title")


This windows application offers the functionality of computing three different centrality metrics for a given undirected weighted network/graph:

- Degree Centrality
- Closeness Centrality
- Betweenness Centrality

Computation is made using C++, and the computed results can then be visualized through an [Electron](https://electronjs.org/) app based on the [D3.js](https://d3js.org/) visualization library.

## Project Setup

### Dependencies 

- [Node.js](https://nodejs.org/):

  To run the visualization app.

- [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10):

  To run the executable algorithm files stored in the `/executables` directory.

### Running the applicatiton

1. Fork or download repo as [zip](https://github.com/omarahmed1111/centrality-algorithms/archive/master.zip).
2. In the repo directory run `cd ./visualization && npm install`.
3. In the `input.txt` file found in the root of the repo, enter the representation of your network as follows:
     1. The first line will contain two integers n,m where n is the number of nodes and m is the number of edges in the graph (1 < n < V, 0 < m < E ). 
     2. This will be followed by m lines describing the edges of the graph. 
     3. Each of the m lines will contain two integers a, b, c that represents an undirected edge between nodes a and b with weight c.
4. execute `run.exe` to compute and visualize the results.

## How it works

When you double click on `run.exe` here's what this executable file goes through:

1. It runs the executable files stored in the `/executables` directory using WSL with`input.txt` as input.
2. These executables produce three different text files. One for the degree centrality measures, one for the closeness centrality measures, and one for the betweenness centrality measures.
3. These three files, as well as `input.txt`, are ran through a script that produce a `.json` file matching the format specified by the visualization library.
4. The `.json` file is then fed to the electron visualization app which plots the graph and displays an interactive table with all the computed centrality measures.

