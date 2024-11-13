#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

void print_environment(const char *env_var) {
    if (env_var) {
        char *value = getenv(env_var);
        if (value) {
            printf("%s=%s\n", env_var, value);
        } else {
            printf("Environment variable '%s' not found.\n", env_var);
        }
    } else {
        extern char **environ;
        for (char **env = environ; *env; ++env) {
            printf("%s\n", *env);
        }
    }
}

void print_user_ids() {
    uid_t real_uid = getuid();
    uid_t effective_uid = geteuid();
    printf("My Realistic User ID: %d\n", real_uid);
    printf("My Valid User ID: %d\n", effective_uid);
}

void print_group_ids() {
    gid_t real_gid = getgid();
    gid_t effective_gid = getegid();
    printf("My Realistic Group ID: %d\n", real_gid);
    printf("My Valid Group ID: %d\n", effective_gid);
}

void print_process_id() {
    printf("my process number:[%d]\n", getpid());
}

void print_parent_process_id() {
    printf("my parent's process number: [%d]\n", getppid());
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s [-e [ENV_VAR]] [-u] [-g] [-i] [-p]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            if (i + 1 < argc && argv[i + 1][0] != '-') {
                print_environment(argv[i + 1]);
                i++; // Skip the next argument as it's the environment variable name
            } else {
                print_environment(NULL);
            }
        } else if (strcmp(argv[i], "-u") == 0) {
            print_user_ids();
        } else if (strcmp(argv[i], "-g") == 0) {
            print_group_ids();
        } else if (strcmp(argv[i], "-i") == 0) {
            print_process_id();
        } else if (strcmp(argv[i], "-p") == 0) {
            print_parent_process_id();
        } else {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
        }
    }

    return 0;
}

