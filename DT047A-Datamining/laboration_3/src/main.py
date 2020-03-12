
import tensorflow_datasets as tfds
import tensorflow as tf

from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Conv2D, Flatten, Dropout, MaxPooling2D
from tensorflow.keras.preprocessing.image import ImageDataGenerator

import os
import numpy as np
import matplotlib.pyplot as plt

# ds_train = tfds.load(name="horses_vs_humans",split="train", shuffle_files=True)

batch_size = 128
epochs = 15
IMG_HEIGHT = 150
IMG_WIDTH = 150

train_dir = "./horse-or-human/train"
validation_dir = "./horse-or-human/validation"

train_horses_dir = "./horse-or-human/train/horses"
train_humans_dir = "./horse-or-human/train/humans"

validation_horses_dir = "./horse-or-human/validation/horses"
validation_humans_dir = "./horse-or-human/validation/humans"

num_horses_tr = len(os.listdir(train_horses_dir))
num_humans_tr = len(os.listdir(train_humans_dir))

num_horses_val = len(os.listdir(validation_horses_dir))
num_humans_val = len(os.listdir(validation_humans_dir))

total_train = num_horses_tr + num_humans_tr
total_val = num_horses_val + num_humans_val

print('total training horses images:', num_horses_tr)
print('total training humans images:', num_humans_tr)

print('total validation horses images:', num_horses_val)
print('total validation humans images:', num_humans_val)
print("--")
print("Total training images:", total_train)
print("Total validation images:", total_val)

train_image_generator = ImageDataGenerator(
    rescale=1./255,
    horizontal_flip=True
)  # Generator for our training data

validation_image_generator = ImageDataGenerator(
    rescale=1./255,
    horizontal_flip=True
)  # Generator for our validation data

train_data_gen = train_image_generator.flow_from_directory(
    batch_size=batch_size,
    directory=train_dir,
    shuffle=True,
    target_size=(
        IMG_HEIGHT,
        IMG_WIDTH
    ),
    class_mode='binary'
)

val_data_gen = validation_image_generator.flow_from_directory(
    batch_size=batch_size,
    directory=validation_dir,
    target_size=(
        IMG_HEIGHT,
        IMG_WIDTH
    ),
    class_mode='binary'
)

# takes out the difference of the images

model = Sequential([
    # Applies some sort of operations, add noise, blur etc.
    # Makes the image more vissible
    Conv2D(16, 3, padding='same', activation='relu', input_shape=(
        IMG_HEIGHT,
        IMG_WIDTH,
        3
    )
    ),
    MaxPooling2D(),  # takes the image and crops it on a specific feature of the image
    Conv2D(32, 3, padding='same', activation='relu'),
    MaxPooling2D(),
    Conv2D(64, 3, padding='same', activation='relu'),
    MaxPooling2D(),
    Flatten(),
    Dense(512, activation='relu'),
    Dense(1)  # num of categories
])

model.compile(
    optimizer='adam',
    loss=tf.keras.losses.BinaryCrossentropy(from_logits=True),
    metrics=['accuracy']
)

model.summary()


history = model.fit_generator(
    train_data_gen,
    steps_per_epoch=total_train // batch_size,
    epochs=epochs,
    validation_data=val_data_gen,
    validation_steps=total_val // batch_size
)

acc = history.history['accuracy']
val_acc = history.history['val_accuracy']

loss = history.history['loss']
val_loss = history.history['val_loss']

epochs_range = range(epochs)
# plt.figure(figsize=(8, 8))
# plt.subplot(1, 2, 1)
plt.plot(epochs_range, acc, label='Training Accuracy')
plt.plot(epochs_range, val_acc, label='Validation Accuracy')
plt.legend(loc='lower right')
plt.title('Training and Validation Accuracy')

# plt.subplot(1, 2, 2)
# plt.plot(epochs_range, loss, label='Training Loss')
# plt.plot(epochs_range, val_loss, label='Validation Loss')
# plt.legend(loc='upper right')
# plt.title('Training and Validation Loss')
plt.tight_layout()
plt.savefig("Result_" + str(IMG_HEIGHT) + "x" +
            str(IMG_WIDTH) + "_batch_" + str(batch_size) + ".png")
