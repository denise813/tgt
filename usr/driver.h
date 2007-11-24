extern struct backingstore_template mmap_bst, sync_bst, sg_bst;

struct tgt_driver {
	const char *name;
	int use_kernel;

	int (*init)(int, char *);

	int (*target_create)(struct target *);
	void (*target_destroy)(int);

	int (*lu_create)(struct scsi_lu *);

	int (*update)(int, int, char *);
	int (*show)(int, int, uint64_t, uint32_t, uint64_t, char *, int);

	uint64_t (*scsi_get_lun)(uint8_t *);

	int (*cmd_end_notify)(uint64_t nid, int result, struct scsi_cmd *);
	int (*mgmt_end_notify)(struct mgmt_req *);

	struct backingstore_template *default_bst;
};

extern struct tgt_driver *tgt_drivers[];
extern int get_driver_index(char *name);
extern int register_driver(struct tgt_driver *drv);

