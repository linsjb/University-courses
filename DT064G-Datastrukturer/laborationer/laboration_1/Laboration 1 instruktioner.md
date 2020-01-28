# Laboration 1, Grafer
Laborationen behandlar elementära grafalgoritmer.

## Syfte
Öva implementation av en enkel minimum spanning tree algoritm och kontrollera dess beteende för olika grafer.

## Tidsåtgång
Två tillfällen är avsatt för detta.

## Redovisning
Programkod för:
- Depth-First Search och Breath-First Search algoritmerna för kontroll av sammanhängande graf
- Dijkstras algoritm

**Rapport ska innehålla:**

Programkörningar av 4 olika grafer.

Gör det troligt att Dijkstras algoritm är korrekt. Skriv en redogörelse som förklarar Djikstras algoritm och varför den ger ett korrekt resultat. Antingen så formulerar du det som ett matematiskt bevis eller så redogör för det med ett resonemang i ord.

En beskrivning av ditt laborerande skriven så att en kurskamrat som inte känner till algoritmerna eller labbproceduren ska kunna återskapa dina resultat.



## Uppgifter
Implementera ett gränssnitt för att läsa in en godtycklig graf

Detta kan göras på valfritt sätt. 2 dimensionell matris rekommenderas.

Implementera Depth-First Search och Breath-First Search för att avgöra om grafen är sammanhängande **

Varför måste detta göras?

Implementera Dijkstras algoritm

Testkörning av algoritmerna med resultat.



** -(Clarification: DFS and BFS have to be used to check that the graph is valid. A disconnected graph would be an example of an invalid graph. So, your need to use BFS and DFS to make sure that EVERY node in the graph can be reached from ANY node in the graph. /Elijs)
