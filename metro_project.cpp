



#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include<algorithm>
using namespace std;

// Structure to represent a metro station
struct Station {
    string name;
    vector<pair<int, int>> connections; // connected station index and distance
};

// Class to represent the metro network
class Metro {
private:
    vector<Station> stations;

public:
    // Function to add a station to the network
    void addStation(const string& name) {
        stations.push_back({name, {}});
    }

    // Function to add a connection between two stations with a given distance
    void addConnection(int stationIndex1, int stationIndex2, int distance) {
        stations[stationIndex1].connections.push_back({stationIndex2, distance});
        stations[stationIndex2].connections.push_back({stationIndex1, distance});
    }

    // Function to find the shortest path using Dijkstra's algorithm
    vector<int> findShortestPath(int source, int destination) {
        vector<int> distance(stations.size(), numeric_limits<int>::max());
        vector<int> parent(stations.size(), -1);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (const auto& connection : stations[u].connections) {
                int v = connection.first;
                int w = connection.second;

                if (distance[u] + w < distance[v]) {
                    distance[v] = distance[u] + w;
                    parent[v] = u;
                    pq.push({distance[v], v});
                }
            }
        }

        // Reconstruct the path
        vector<int> path;
        for (int v = destination; v != -1; v = parent[v]) {
            path.push_back(v);
        }

        reverse(path.begin(), path.end());
        return path;
    }

    // Function to display the shortest path between stations
    void displayShortestPath(int source, int destination) {
        vector<int> shortestPath = findShortestPath(source, destination);

        // Print the result
        cout << "Shortest path from " << stations[source].name << " to " << stations[destination].name << ": "<<endl;
        for (int stationIndex : shortestPath) {
            cout << stations[stationIndex].name << " -> ";
        }
        cout << "\n";
    }
};

int main() {
    // Create a metro network
    Metro metro;
    metro.addStation("Gandhi Nagar");
    metro.addStation("Karond");
    metro.addStation("Berasia");
    metro.addStation("Budhwara");
    metro.addStation("Jahangirabad");
    metro.addStation("Roushanpura");
    metro.addStation("Kotra Sultanabad");
    metro.addStation("Nehru Nagar");
    metro.addStation("Shyamla Hills");
    metro.addStation("Van Vihar");
    metro.addStation("Jawahar Chowk");
    metro.addStation("Rangmahal");
    metro.addStation("Vidhan Sabha");
    metro.addStation("MP Nagar");
    metro.addStation("6 no. stop");
    metro.addStation("Shivaji Nagar");
    metro.addStation("Char imli");
    metro.addStation("Bittan Market");
    metro.addStation("Shahpura");
    metro.addStation("Gulmohar");
    metro.addStation("Akriti Eco City");
    metro.addStation("Saliya");
    metro.addStation("Chandbad");
    metro.addStation("Ashoka Garden");
    metro.addStation("Govindpura");
    metro.addStation("Minal");
    metro.addStation("Piplani");
    metro.addStation("Ayodhya Bypass");
    metro.addStation("Anand Nagar");
    metro.addStation("Awadhpuri");
    metro.addStation("Barkheda Pathani");
    metro.addStation("Saket Nagar");
    metro.addStation("AIIMS");
    metro.addStation("Barkatullah University");
    metro.addStation("Misrod");
    metro.addStation("Ratanpur");
    metro.addStation("Bairagarh");
    metro.addStation("Lalghati");
    metro.addStation("Tajul Masjid");
    metro.addStation("Hamidia Hospital");
    metro.addStation("Kamla PArk");
    metro.addStation("Polytechnic Square");
    metro.addStation("Roshanpura");
    metro.addStation("New Market");
    metro.addStation("Mata MAndir");
    metro.addStation("MANIT Square");
    metro.addStation("Patrakar Colony");
    metro.addStation("Chuna Bhatti");
    metro.addStation("Sarvdharm");
    metro.addStation("Bima Kunj");
    metro.addStation("Danish Kunj");
    metro.addStation("Nayapura");
    metro.addStation("Bairagarh Chichli");
    
    metro.addConnection(0, 1, 5); // Connection between Station A and Station B with distance 5
    metro.addConnection(1, 2, 3); // Connection between Station B and Station C with distance 3
    metro.addConnection(2, 3, 6);
    metro.addConnection(3, 4, 8);
    metro.addConnection(4, 42, 18);
    metro.addConnection(42, 43, 6);
    metro.addConnection(42, 41, 6);
    metro.addConnection(42, 6, 24);
    metro.addConnection(6, 7, 4);
    metro.addConnection(7, 8, 8);
    metro.addConnection(41, 42, 5);
    metro.addConnection(40, 41, 6);
    metro.addConnection(39, 40, 3);
    metro.addConnection(38, 39, 3);
    metro.addConnection(37, 38, 4);
    metro.addConnection(36, 37, 4);
    metro.addConnection(43, 11, 5);
    metro.addConnection(10, 11, 3);
    metro.addConnection(9, 10, 7);
    metro.addConnection(43, 12, 12);
    metro.addConnection(12, 13, 8);
    metro.addConnection(43, 44, 3);
    metro.addConnection(44, 45, 6);
    metro.addConnection(45, 46, 4);
    metro.addConnection(46, 47, 4);
    metro.addConnection(47, 48, 6);
    metro.addConnection(48, 49, 6);
    metro.addConnection(49, 50, 6);
    metro.addConnection(50, 51, 6);
    metro.addConnection(51, 52, 3);
    metro.addConnection(52, 21, 7);
    metro.addConnection(20, 21, 3);
    metro.addConnection(19, 20, 3);
    metro.addConnection(18, 19, 2);
    metro.addConnection(17, 18, 4);
    metro.addConnection(16, 17, 3);
    metro.addConnection(15, 16, 3);
    metro.addConnection(14, 15, 3);
    metro.addConnection(14, 13, 5);
    metro.addConnection(13, 22, 7);
    metro.addConnection(22, 23, 3);
    metro.addConnection(13, 24, 6);
    metro.addConnection(24, 25, 3);
    metro.addConnection(25, 26, 2);
    metro.addConnection(26, 27, 2);
    metro.addConnection(27, 28, 3);
    metro.addConnection(28, 29, 5);
    metro.addConnection(29, 30, 4);
    metro.addConnection(30, 31, 5);
    metro.addConnection(31, 32, 4);
    metro.addConnection(32, 33, 3);
    metro.addConnection(33, 34, 3);
    metro.addConnection(34, 35, 3);
   
    

    // Example: Find the shortest path from Station A to Station C
    int source = 0; // Station A
    int destination = 34; // Station C

    metro.displayShortestPath(source, destination);

    return 0;
}
