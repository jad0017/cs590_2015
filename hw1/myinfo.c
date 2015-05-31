#include <sys/types.h>

#include <errno.h>
#include <pwd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* HOST_NAME_MAX or a value of at least 255 should be used. */
#define HOSTNAME_LEN 255

#define ERROR(...) fprintf(stderr, __VA_ARGS__)

int
main(void)
{
	int err;

	struct passwd *pwd;
	
	char hostname[HOSTNAME_LEN + 1];

	/* getuid() cannot fail, passthrough to get passwd struct
	 * for running user. */
	pwd = getpwuid(getuid());

	if (pwd == NULL) {
		ERROR("Failed to retreive user information: (%d) %s\n",
			errno, strerror(errno));
		return EXIT_FAILURE;
	}

	err = gethostname(hostname, HOSTNAME_LEN);

	if (err != 0) {
		ERROR("Failed to retreive hostname: (%d) %s\n",
			errno, strerror(errno));
		return EXIT_FAILURE;
	}


	printf(
		"------------------------------\n"
		"System Information:\n"
		"  System Name: %s\n"
		"\n"
		"User Information:\n"
		"  Full Name: %s\n"
		"  Log Name: %s\n"
		"  UID: %d\n"
		"  GID: %d\n"
		"  HOME Directory: %s\n"
		"  Default Shell: %s\n"
		"------------------------------\n",
		hostname,
		pwd->pw_gecos, pwd->pw_name,
		pwd->pw_uid, pwd->pw_gid,
		pwd->pw_dir,
		pwd->pw_shell
	);

	system("date");

	return EXIT_SUCCESS;
}
