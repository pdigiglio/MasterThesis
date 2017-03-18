// Create an empty YAP model.
unique_ptr<Model> M(make_unique<ZemachFormalism>());

// Open the PDL table with the particle properties.
auto F = read_pdl_file("evt.pdl");

// Create the final state particles.
auto piPlus  = FinalStateParticle::create(F[ 211]);
auto piMinus = FinalStateParticle::create(F[-211]);

// Set the final state of the decay.
M->setFinalState(piPlus, piMinus, piPlus);

// Use a common radial size for all the resonance.
constexpr double radial_size = 3.; // [1/GeV]

// Create the initial state particle.
auto D = DecayingParticle::create(F["D+"], radial_size);

// -- rho0 ----------------- 
constexpr double rho_m = 775.49e-3; // mass in GeV/c^2
constexpr double rho_w = 149.4e-3;  // width in GeV/c^2
auto rho0 = DecayingParticle::create(F[113], radial_size,
    make_shared<RelativisticBreitWigner>(rho_m, rho_w));
rho0->addStrongDecay(piPlus, piMinus);
D->addWeakDecay(rho0, piPlus);

// -- f0(980) -------------- 
auto f0_fl = make_shared<Flatte>(.965);
f0_fl->add(FlatteChannel(.406 * .406, *piPlus, *piMinus));
auto f0 = DecayingParticle::create("f_0",
    F["f_0"].quantumNumbers(), radial_size, f0_fl);
f0->addStrongDecay(piPlus, piMinus);
D->addWeakDecay(f0, piPlus);

// -- f0(1500) ------------- 
auto f0_1500 = // same as rho0 [...]

// -- sigma i.e. f0(500) --- 
auto f0_500 = DecayingParticle::create(F["f_0(500)"],
    radial_size,
    make_unique<PoleMass>(complex<double>(.470, -.220)));
f0_500->addStrongDecay(piPlus, piMinus);
D->addWeakDecay(f0_500, piPlus);

// Set the decay initial state.
M->addInitialState(D);
// Lock the model before setting the free amplitudes.
M->lock();

// Fix the wave free amplitudes.
*free_amplitude(*M, to(rho0))    = polar(1.,  0.);
*free_amplitude(*M, to(f0))      = polar(1.4, rad(12.));
*free_amplitude(*M, to(f0_1500)) = polar(1.1, rad(-44.));
*free_amplitude(*M, to(f0_500))  = polar(3.7, rad(-3.));
