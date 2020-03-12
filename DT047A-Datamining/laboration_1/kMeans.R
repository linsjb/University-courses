# Course: Datamining
# Laboration: one
# Authors: Diana Saveh & Linus Sjöbro
# Date: 2020-02-04

Iris <- read.csv('/users/linussjobro/code/github/University-courses/laboration_1/data/iris.data', header= FALSE)

names(Iris) [names(Iris) == "V1"] <- "Sepal.Length"
names(Iris) [names(Iris) == "V2"] <- "Sepal.Width" 
names(Iris) [names(Iris) == "V3"] <- "Petal.Length"
names(Iris) [names(Iris) == "V4"] <- "Petal.Width"
names(Iris) [names(Iris) == "V5"] <- "Species"

Iris.features <- Iris
Iris.features$Species <- NULL

results <- kmeans(Iris.features, 3)

results$cluster
results$betweenss

tableResult <- table(Iris$Species, results$cluster)

write.csv(tableResult, "Laboration_1/results/K-means/table.csv")

png(filename="laboration_1/results/K-means/kMeansPetalCluster.png")
    plot(Iris[c("Petal.Length", "Petal.Width")], col=results$cluster)
dev.off()

png(filename="laboration_1/results/K-means/kMeansPetalSpecies.png")
    plot(Iris[c("Petal.Length", "Petal.Width")], col=Iris$Species)
dev.off()

png(filename="laboration_1/results/K-means/kMeansSepalCluster.png")
    plot(Iris[c("Sepal.Length", "Sepal.Width")], col=results$cluster)
dev.off()

png(filename="laboration_1/results/K-means/kMeansSepalSpecies.png")
    plot(Iris[c("Sepal.Length", "Sepal.Width")], col=Iris$Species)
dev.off()
tableResult