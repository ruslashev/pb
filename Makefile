cxx = g++
cflags = -g -std=c++17 -Wall -Wextra
bin = pb
lflags = -static
src = main.cc card.cc tests.cc
builddir = .build
obj = $(src:%.cc=$(builddir)/obj/%.o)
deps = $(src:%.cc=$(builddir)/dep/%.d)
depcflag = -MD -MP -MF $(@:$(builddir)/obj/%.o=$(builddir)/dep/%.d)

all: $(bin)
	./$(bin)

$(bin): $(obj)
	@echo ld $(@F)
	@$(cxx) $(lflags) $^ -o $@

$(builddir)/obj/%.o: %.cc
	@echo cxx $(<F)
	@$(cxx) $(cflags) $< -o $@ -c $(depcflag)

$(obj): | $(builddir)

$(builddir):
	@mkdir -p $(builddir)/obj
	@mkdir -p $(builddir)/dep

clean:
	rm -rf $(builddir) $(bin)

-include $(deps)

