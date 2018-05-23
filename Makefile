
python_test:
	$(MAKE) -C python test

test: python_test

.PHONY: python_test test


