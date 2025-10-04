# Build target
all: fluix

fluix:
	gcc	src/backend/src/main.c \
		src/backend/include/launch.c \
		src/backend/include/admin.c \
		src/backend/include/user.c \
		src/backend/include/utils.c \
		-o fluix.exe

# Run target
run: fluix
	.\fluix.exe