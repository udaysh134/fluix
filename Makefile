# Build target
all: fluix

fluix:
	gcc	src/backend/src/main.c \
		src/backend/src/launch.c \
		src/backend/src/admin.c \
		src/backend/src/user.c \
		src/backend/src/bot.c \
		src/backend/src/data.c \
		src/backend/src/utils.c \
		\
		src/backend/packages/cJSON/cJSON.c \
		-o Fluix.exe

# Run target
run: fluix
	.\Fluix.exe