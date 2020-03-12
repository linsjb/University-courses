
iris <- read.csv('/users/linussjobro/code/github/University-courses/laboration_1/data/iris.data', header= FALSE)

names (iris) [names(iris) == "V1"] <- "Sepal.Length"
names (iris) [names(iris) == "V2"] <- "Sepal.Width"
names (iris) [names(iris) == "V3"] <- "Petal.Length"
names (iris) [names(iris) == "V4"] <- "Petal.Width"
names (iris) [names(iris) == "V5"] <- "Species"

set.seed(20)

runif(5)
gp <- runif(nrow(iris))
iris <- iris[order(gp), ]

summary(iris[,c(1,2,3,4)])

normalize <- function(x) {
  return((x - min(x)) / (max(x) - min(x)))
}

iris_n <- as.data.frame(lapply(iris[,c(1,2,3,4)], normalize))

iris_train <- iris_n[1:119,]
iris_test <- iris_n[120:150,]

iris_train_target <- iris[1:119, 5]
iris_test_target <- iris[120:150, 5]

library(class)
require(class)

model <- knn(train=iris_train, test=iris_test, cl=iris_train_target, k=40)
result <- table(iris_test_target, model)

result
write.csv(result, "laboration_1/results/KNN/result.csv")
